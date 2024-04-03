
from django.shortcuts import render, get_object_or_404
from .forms import SignUpForm
from django.shortcuts import redirect
from django.views.generic.edit import CreateView, UpdateView, DeleteView
from .models import User, Questionnaire, Question, Answer, Game, Participant
from django.urls import reverse
from django.contrib.auth import authenticate, login
from django.views import generic
from django.contrib.auth.mixins import LoginRequiredMixin, UserPassesTestMixin
from django.urls import reverse_lazy
from django.http import HttpResponse

class HomeView(LoginRequiredMixin, generic.ListView):
    template_name="home.html"
    def get_queryset(self):
        return (
            (Questionnaire.objects.filter(user=self.request.user)
            .order_by('updated_at'))[:5]
        )



def signup(request):
    #si hay una request
    if request.method == 'POST':


        #se utiliza el request form creado
        form = SignUpForm(request.POST)
        if form.is_valid():
            user = form.save()
            user.refresh_from_db()  

            #si todo es correcto se guarda la información y se inicia sesión
            user.save()
            raw_password = form.cleaned_data.get('password1')

            user = authenticate(username=user.username, password=raw_password)
            login(request, user)


            return redirect("/home/")

    else:
        form = SignUpForm()

    return render(request, 'registration/signup.html', {'form': form})


class ejemplo(UpdateView):
    pass

class QuestionnaireDetailView(LoginRequiredMixin, 
                              UserPassesTestMixin, generic.DetailView):
    model = Questionnaire
    template_name="services/questionnaire_detail.html"
    slug_field = 'id'

    def test_func(self):
        questionnaire = self.get_object()
        if questionnaire.user.username == self.request.user.username:
            return True
        return False
    
    def get_context_data(self, **kwargs):
        context_data = super().get_context_data(**kwargs)
        context_data['questionnaire'] = Questionnaire.objects.get(
            id=self.kwargs['pk']) 
        
        context_data['questions'] = (
            Question.objects.filter(
            questionnaire=context_data['questionnaire']))
        
        return context_data
    
class QuestionnaireListView(LoginRequiredMixin,
                             generic.ListView):
    template_name="services/questionnaire_list.html"
        
    def get_queryset(self):
        return (
            Questionnaire.objects.filter(user=self.request.user)
        )



class QuestionnaireRemoveView(LoginRequiredMixin,
                              UserPassesTestMixin, DeleteView):
    model = Questionnaire
    template_name="services/questionnaire_confirm_delete.html"

    def test_func(self):
        questionnaire = self.get_object()
        if questionnaire.user.username == self.request.user.username:
            qs = Question.objects.filter(questionnaire=self.kwargs['pk'])

            for i in qs:
                answers = Answer.objects.filter(question=i)
                answers.delete()

            qs.delete()
            
            return True
        return False

    def get_success_url(self):
        return reverse_lazy('questionnaire-list')
    
class QuestionnaireUpdateView(LoginRequiredMixin, 
                            UserPassesTestMixin, UpdateView):
    model = Questionnaire
    fields = ['title']
    template_name = 'services/questionnaire_form.html'

    def test_func(self):
        questionnaire = self.get_object()
        if questionnaire.user.username == self.request.user.username:
            return True
        return False

    def get_success_url(self):
        return reverse_lazy('questionnaire-detail', 
                            kwargs={'pk': self.object.pk})
    
class QuestionnaireCreateView(LoginRequiredMixin, CreateView):
    model = Questionnaire
    fields = ['title']
    template_name = 'services/questionnaire_form.html'

    def form_valid(self, form):
        form.instance.user = self.request.user
        return super().form_valid(form)

    def get_success_url(self):
        return reverse_lazy('questionnaire-detail', 
                            kwargs={'pk': self.object.pk})
    

class QuestionDetailView(LoginRequiredMixin, 
                         UserPassesTestMixin, 
                         generic.DetailView):
    model = Question
    template_name = 'services/question_detail.html'

    def test_func(self):
        question= self.get_object()
        if question.questionnaire.user.username == self.request.user.username:
            return True
        return False
    def get_queryset(self):
        qs = super(QuestionDetailView, self).get_queryset()
        # check questio belongs to user
        return qs.filter(pk=self.kwargs['pk'])

    # def get_context_data(self, **kwargs):
    #     context_data = super().get_context_data(**kwargs)
    #     context_data['question'] = Question.objects.get(
    #         id=self.kwargs['pk']) 
    #     context_data['answers'] = Answer.objects.filter(
    #         question=context_data['question']) 

class QuestionRemoveView(LoginRequiredMixin, 
                         UserPassesTestMixin, 
                         DeleteView):
    model = Question
    template_name="services/question_confirm_delete.html"


    def test_func(self):
        question = self.get_object()
        if question.questionnaire.user.username == self.request.user.username:
            answers = Answer.objects.filter(question=self.kwargs['pk'])
            answers.delete()

            return True
        return False
    
    def get_success_url(self):
        return reverse_lazy('questionnaire-detail', 
                            kwargs={'pk': self.object.questionnaire.pk})
    
class QuestionUpdateView(LoginRequiredMixin, 
                         UserPassesTestMixin, UpdateView):
    model = Question
    fields = ['question', 'answerTime']
    template_name = 'services/question_form.html'




    def test_func(self):
        question = self.get_object()
        if question.questionnaire.user.username == self.request.user.username:
            return True
        return False

    def get_success_url(self):
        return reverse_lazy('questionnaire-detail', 
                            kwargs={'pk': self.object.questionnaire.id})
    

    
class QuestionCreateView(LoginRequiredMixin,
                         UserPassesTestMixin, 
                        CreateView):
    model = Question
    fields = ['question', 'answerTime']
    template_name = 'services/question_form.html'
   
    def form_valid(self, form):
        form.instance.user = self.request.user
        form.instance.questionnaire = Questionnaire.objects.get(id=self.kwargs['questionnaireid'])
        
        return super().form_valid(form)

    def test_func(self):
        questionnaire = Questionnaire.objects.get(
            id=self.kwargs['questionnaireid'])
        if questionnaire.user.username == self.request.user.username:
            return True
        return False

    def get_success_url(self):
        return reverse_lazy('questionnaire-detail', kwargs={
            'pk': self.kwargs['questionnaireid']})


class AnswerCreateView(LoginRequiredMixin,
                       UserPassesTestMixin,
                       CreateView):
    model = Answer
    fields = ['answer', 'correct']
    template_name = 'services/answer_form.html'


    
    def form_valid(self, form):
        form.instance.user = self.request.user
        form.instance.question = Question.objects.get(id=self.kwargs['questionid'])

        qs = Answer.objects.filter(question=form.instance.question )
        if qs == 4:
            return HttpResponse('Error: no mas de 4 respuestas.')
        else:
            return super().form_valid(form)

    
    def test_func(self):
        question = Question.objects.get(
            id=self.kwargs['questionid'])
        if question.questionnaire.user.username == self.request.user.username:
            return True
        return False

    def get_success_url(self):
        return reverse_lazy('question-detail', kwargs={
            'pk': self.kwargs['questionid']})

class AnswerRemoveView(LoginRequiredMixin, UserPassesTestMixin, DeleteView):
    model = Answer
    template_name="services/answer_confirm_delete.html"
    

    def test_func(self):
        answer = self.get_object()
        if answer.question.questionnaire.user.username == self.request.user.username:
            return True
        return False
    
    def get_success_url(self):
        return reverse_lazy('question-detail', 
                            kwargs={'pk': self.object.question.id})


class AnswerUpdateView(LoginRequiredMixin, 
                         UserPassesTestMixin, UpdateView):
    model = Answer
    fields = ['answer', 'correct']
    template_name = 'services/answer_form.html'

    def test_func(self):
        answer = self.get_object()
        if answer.question.questionnaire.user.username == self.request.user.username:
            return True
        return False

    def get_success_url(self):
        return reverse_lazy('question-detail', 
                            kwargs={'pk': self.object.question.id})
    

class GameCreateView(LoginRequiredMixin, CreateView):
    model = Game
    fields = []
    template_name = 'services/game_start.html'

    def form_valid(self, form):
        questionnaire = Questionnaire.objects.get(id=self.kwargs['pk'])
        if questionnaire.user.username == self.request.user.username:
            form.instance.questionnaire = questionnaire
            form.instance.user = questionnaire.user

            qs = Question.objects.filter(questionnaire=questionnaire)

            tiempo:int = 0
            preguntas:int = 0

            for i in qs:
                tiempo+= i.answerTime
                preguntas+=1

            form.instance.countdownTime = tiempo
            form.instance.questionNo = preguntas
            
            return super().form_valid(form)
        else:
            return HttpResponse('Error: You are not the author of the questionnaire.')

    def get_success_url(self):
        game_id = self.object.id
        self.request.session['game_id'] = game_id
        return reverse_lazy('game-create', kwargs={'pk': game_id})
    
class GameUpdateParticipant (LoginRequiredMixin, generic.ListView):
    model=Participant
