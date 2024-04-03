
from django.shortcuts import render
from .forms import SignUpForm, QuestionnaireCreateForm
from .forms import QuestionCreateForm, ParticipantJoinForm
from django.shortcuts import redirect
from django.views.generic.edit import CreateView
from django.views.generic.edit import UpdateView
from django.views.generic.edit import DeleteView
from django.views.generic import View, TemplateView
from .models import Questionnaire, Question, Guess
from .models import Answer, Game, Participant, User
from django.contrib.auth import authenticate, login
from django.views import generic
from django.contrib.auth.mixins import LoginRequiredMixin
from django.contrib.auth.mixins import UserPassesTestMixin
from django.urls import reverse_lazy
from django.http import HttpResponse
from django.http import HttpResponseNotAllowed
from django.http import HttpResponseRedirect
import time

from rest_framework import viewsets
from .serializers import UserSerializer
from .serializers import AnswerSerializer
from .serializers import GameSerializer
from .serializers import ParticipantSerializer
from .serializers import GuessSerializer
from django.shortcuts import get_object_or_404
from rest_framework.response import Response
from rest_framework.permissions import AllowAny
from rest_framework import status

#author: Sergio Hidalgo
class SingupView(generic.CreateView):
    model = User
    form_class = SignUpForm
    template_name = 'registration/signup.html'

    def form_valid(self, form):

        if form.is_valid():

            user = form.save()
            user.refresh_from_db()

            self.password = form.cleaned_data['password1']
            self.username = form.cleaned_data['username']

            return super().form_valid(form)
    
    def get_success_url(self) -> str:

        user =  authenticate(username=self.username, 
                     password=self.password)
        login(self.request, user)

        return reverse_lazy('home')

#author: Sergio Hidalgo
class HomeView(generic.ListView):

    template_name = "home.html"
    model = Questionnaire

    def get_context_data(self, **kwargs):
        context_data = (super().
                        get_context_data(**kwargs))
        if not (self.request.user.username
                in 'AnonymousUser'):
            u = self.request.user
            q = Questionnaire.objects.filter(
                user=u).order_by('-updated_at')[:5]
            context_data['latest_questionnaire_list'] = q

        return context_data


#author: Sergio Hidalgo
class QuestionnaireDetailView(LoginRequiredMixin,
                              UserPassesTestMixin, generic.DetailView):
    model = Questionnaire
    template_name = "services/questionnaire_detail.html"

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


#author: Miguel Ibañez
class QuestionnaireListView(LoginRequiredMixin,
                            generic.ListView):
    template_name = "services/questionnaire_list.html"

    def get_queryset(self):
        return (
            Questionnaire.objects.filter(user=self.request.user)
        )


#author: Sergio Hidalgo
class QuestionnaireRemoveView(LoginRequiredMixin,
                              UserPassesTestMixin, DeleteView):
    model = Questionnaire
    template_name = "services/questionnaire_confirm_delete.html"

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


#author: Sergio Hidalgo
class QuestionnaireUpdateView(LoginRequiredMixin,
                              UserPassesTestMixin, UpdateView):
    model = Questionnaire
    template_name = 'services/questionnaire_form.html'
    form_class = QuestionnaireCreateForm



    def test_func(self):
        questionnaire = self.get_object()
        if questionnaire.user.username == self.request.user.username:
            return True
        return False

    def get_success_url(self):
        return reverse_lazy('questionnaire-detail',
                            kwargs={'pk': self.object.pk})


#author: Sergio Hidalgo
class QuestionnaireCreateView(LoginRequiredMixin, CreateView):
    model = Questionnaire
    template_name = 'services/questionnaire_form.html'
    form_class = QuestionnaireCreateForm

    def form_valid(self, form):
        if form.is_valid():
            form.instance.user = self.request.user
        return super().form_valid(form)
    

    def get_success_url(self):
        return reverse_lazy('questionnaire-detail',
                            kwargs={'pk': self.object.pk})


#author: Miguel Ibañez
class QuestionDetailView(LoginRequiredMixin,
                         UserPassesTestMixin,
                         generic.DetailView):
    model = Question
    template_name = 'services/question_detail.html'

    def test_func(self):
        question = self.get_object()
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


#author: Sergio Hidalgo
class QuestionRemoveView(LoginRequiredMixin,
                         UserPassesTestMixin,
                         DeleteView):
    model = Question
    template_name = "services/question_confirm_delete.html"

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


#author: Sergio Hidalgo
class QuestionUpdateView(LoginRequiredMixin,
                         UserPassesTestMixin, UpdateView):
    model = Question
    template_name = 'services/question_form.html'
    form_class = QuestionCreateForm

    def test_func(self):
        question = self.get_object()
        if question.questionnaire.user.username == self.request.user.username:
            return True
        return False

    def get_success_url(self):
        return reverse_lazy('questionnaire-detail',
                            kwargs={'pk': self.object.questionnaire.id})


#author: Sergio Hidalgo
class QuestionCreateView(LoginRequiredMixin,
                         UserPassesTestMixin,
                         CreateView):
    model = Question
    template_name = 'services/question_form.html'
    form_class = QuestionCreateForm

    def form_valid(self, form):
        if form.is_valid():
            form.instance.user = self.request.user
            form.instance.questionnaire = Questionnaire.objects.get(
                id=self.kwargs['questionnaireid'])

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


#author: Sergio Hidalgo
class AnswerCreateView(LoginRequiredMixin,
                       UserPassesTestMixin,
                       CreateView):
    model = Answer
    fields = ['answer', 'correct']
    template_name = 'services/answer_form.html'

    def form_valid(self, form):
        if form.is_valid():
            form.instance.user = self.request.user
            form.instance.question = Question.objects.get(
                id=self.kwargs['questionid'])

            qs = Answer.objects.filter(question=form.instance.question).count()
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


#author: Miguel Ibañez
class AnswerRemoveView(LoginRequiredMixin, UserPassesTestMixin, DeleteView):
    model = Answer
    template_name = "services/answer_confirm_delete.html"

    def test_func(self):
        answer = self.get_object()
        user = answer.question.questionnaire.user
        if user.username == self.request.user.username:
            return True
        return False

    def get_success_url(self):
        return reverse_lazy('question-detail',
                            kwargs={'pk': self.object.question.id})


#author: Sergio Hidalgo
class AnswerUpdateView(LoginRequiredMixin,
                       UserPassesTestMixin, UpdateView):
    model = Answer
    fields = ['answer', 'correct']
    template_name = 'services/answer_form.html'

    def test_func(self):
        answer = self.get_object()
        user = answer.question.questionnaire.user
        if user.username == self.request.user.username:
            return True
        return False

    def get_success_url(self):
        return reverse_lazy('question-detail',
                            kwargs={'pk': self.object.question.id})

#author: Sergio Hidalgo
class GameCreateView(LoginRequiredMixin,
                     UserPassesTestMixin,
                     generic.DetailView,
                     View):

    model = Game
    template_name = 'services/game_start.html'

    def test_func(self):
        questionnaire = Questionnaire.objects.get(
            id=self.kwargs['questionnaireid'])
        if questionnaire.user.username == self.request.user.username:
            return True
        return False

    def get(self, request, *args, **kwargs):
        questionnaire = Questionnaire.objects.get(
            id=self.kwargs['questionnaireid'])

        g = Game(questionnaire=questionnaire)
        g.save()

        context = dict()

        context = {'game': Game.objects.get(id=g.id)}

        request.session['publicId'] = context['game'].publicId
        request.session['state'] = context['game'].state
        self.request.session['next'] = 0

        return render(request, self.template_name, context)


#author: Sergio Hidalgo
class GameUpdateParticipantView (LoginRequiredMixin,
                                 UserPassesTestMixin,
                                 generic.ListView):
    model = Participant
    template_name = 'services/participant_update.html'

    def test_func(self):
        game = Game.objects.get(
            publicId=self.kwargs['publicid'])
        if game.questionnaire.user.username == self.request.user.username:
            return True
        return False


    def get_queryset(self):

        qs = super(GameUpdateParticipantView, self).get_queryset()

        qs = qs.filter(game=Game.objects.get(publicId=self.kwargs['publicid']))

        return qs

#author: Sergio Hidalgo
class GameJoinParticipantView(generic.CreateView):
    model = Participant
    form_class = ParticipantJoinForm
    template_name = 'services/participant_form.html'

    def form_valid(self, form):

        if form.is_valid():


            g = Game.objects.get(publicId=int(form.cleaned_data['publicId']))
            
            form.instance.game = g

            return super().form_valid(form)
    
    def get_success_url(self):
        return reverse_lazy('game-join')



#author: Miguel Ibañez
#detail of the game
class GameDetailView(LoginRequiredMixin,
                         UserPassesTestMixin,
                         generic.DetailView):
    model = Game
    template_name = 'services/game_detail.html'
    slug_field = 'publicId'
    slug_url_kwarg = 'publicId'

    def test_func(self):
        game = get_object_or_404(Game, publicId=self.kwargs['publicId'])
        if game.questionnaire.user.username == self.request.user.username:
            return True
        return False
    
    def get_queryset(self):
        qs = super(GameDetailView, self).get_queryset()
        # check questio belongs to user
        return qs.filter(publicId=self.kwargs['publicId'])



#author: Sergio Hidalgo
#This view will do the logic of the kahoot
class GameCountDownView ( generic.ListView):
    model = Game
    first_count = True

    #Function to process Ajax call
    def post(self, request, *args: str, **kwargs: any) :

        #If isnt ajax or POST is not allowed
        if not request.is_ajax() or not request.method=='POST':
            return HttpResponseNotAllowed(['POST'])
        
        if  request.session['state'] != 4:
        
            #it makes the 'next' to 1 (it will be used laters)
            request.session['next'] = 1
            return HttpResponse('next')
        

        #if it wasnt a "next" call, it will be a "reset" one
        game = Game.objects.filter(publicId=self.request.session['publicId'])
        #resets all participants points        
        Participant.objects.filter(game=game[0]).update(points=0)
        #delete guesses 
        Guess.objects.filter(game=game[0]).delete()
        #and resets game countdown, questionno and state
        Game.objects.filter(publicId=self.request.session['publicId']).update(state=1,
                                                                              countdownTime=9, 
                                                                              questionNo =1)
        #sessions are reseted too
        request.session['state'] = 1
        request.session['next'] = 0
        self.first_count = False

        return HttpResponse('reset')



    def get_template_names(self):

        #WAITING
        if self.request.session['state'] == 1:

            #the first count its the teamplate that have 
            #the div refreshed by ajax
            if self.first_count == True:
                return 'services/game_countdown.html'

            else:
                #the template that shows the number
                return 'services/count_update.html'
            
        #QUESTION
        if self.request.session['state'] == 2:
            #the template that shows the question
            return 'services/game_question.html'
        
        #ANSWER
        if self.request.session['state'] == 3:
            #the template that shows the answer
            return 'services/game_answer.html'
        
        #LEADERBOARD
        if self.request.session['state'] == 4:
            #the template that shows the leaderboard
            return 'services/game_leaderboard.html'
        
    #Executes the logic of the kahoot 
    def get_context_data(self, **kwargs):
        context_data = (super().
                        get_context_data(**kwargs))

        #Game that we are playing
        game = Game.objects.filter(publicId=self.request.session['publicId'])
        g = game[0]

        #WAITING
        if self.request.session['state'] == 1:

            #get the count number
            context_data['number'] = int(g.countdownTime)
            g.countdownTime -= 1

            #updates the game countdown
            game.update(countdownTime=g.countdownTime)

            #this will prevent the view to load recursively
            #the same template
            if g.countdownTime < 9:
                self.first_count = False

            #when its over it will select the first question answertime
            if g.countdownTime < 0:
                g.countdownTime = Question.objects.filter(
                    questionnaire=g.questionnaire)[0].answerTime
                g.state = 2
                #changes the state to QUESTION 
                game.update(countdownTime=g.countdownTime,
                            state=g.state)
                self.request.session['state'] = 2
    

        #QUESTION
        if self.request.session['state'] == 2:
            #it will prevent the answer state to be skipped
            self.request.session['next'] = 0

            #if the countdownTime its over
            if g.countdownTime <= 0:
                #the player will have 30secs before it
                #skips automatically
                g.countdownTime = 30
                g.state = 3
                #updates the state to ANSWER
                game.update(countdownTime=30, 
                            state=3)
                self.request.session['state'] = 3
            else:
                g.countdownTime -= 1
                game.update(countdownTime=g.countdownTime)

            #gets the context data
            context_data = self.question_context(g, context_data)

        #ANSWER
        if self.request.session['state'] == 3 or self.request.session['next'] == 1:
            #gets the question set
            ques = Question.objects.filter(questionnaire=g.questionnaire)
            #and the question itself
            q = ques[g.questionNo-1]
            #as in game, I do this so I can change the db
            #with db

            #filter correct answers
            a = Answer.objects.filter(question=q, correct=True)
            context_data['answer'] = a
            #correct number of guesses
            context_data['correctno'] = Guess.objects.filter(question=q, answer__in=a).count()
            #total number of guesess
            context_data['guessno'] = Guess.objects.filter(question=q).count()
            #and participants
            context_data['participants'] = Participant.objects.filter(game=g)
            
             
            #if the countdown time its over or the button
            #with the ajax call has been clicked
            if g.countdownTime <= 0 or self.request.session['next'] == 1:

                #it will update the 'next' value
                self.request.session['next'] = 0
                #the question number
                g.questionNo+=1
                
                #LEADERBOARD
                #if it was the last question 
                if g.questionNo > ques.count():
                    #it will change to LEADERBOARD
                    self.request.session['state'] = 4
                    self.request.session['next'] = 1
                    context_data['participants_podium'] = Participant.objects.filter(game=g).order_by('-points')[:3]


                    context_data['podium_list'] = []

                    #Makes the podium list
                    try:

                        #check if it exists
                        if context_data['participants_podium'][1]:
                            context_data['podium_list'].append({'participant' : context_data['participants_podium'][1],
                                                                'class' : "400px", 'number' : 2})
                        
                        if context_data['participants_podium'][0]:
                            #and will apend on the new key list a dict
                            #with the participant and the class
                            context_data['podium_list'].append({'participant' : context_data['participants_podium'][0],
                                                                'class' : "600px", 'number' : 1})

 

                        if context_data['participants_podium'][2]:
                            context_data['podium_list'].append({'participant' : context_data['participants_podium'][2],
                                                                'class' : "250px", 'number' : 3})

                    except: IndexError

                    try:
                                            
                            if context_data['participants_podium'][0]:
                            #and will apend on the new key list a dict
                            #with the participant and the class
                                context_data['podium_list'].append({'participant' : context_data['participants_podium'][0],
                                                                'class' : "600px", 'number' : 1})
                    except: IndexError


                    game.update(state=4)
                    return context_data
                
                #if not, it will update countdown and state
                game.update(countdownTime=q.answerTime, 
                questionNo=g.questionNo, state=2)
                self.request.session['state'] = 2

                #gets question context data so it will be shown instantly
                context_data = self.question_context(g, context_data)

            else:
                g.countdownTime -= 1
                game.update(countdownTime=g.countdownTime)
            

   
        return context_data

    def question_context(self, g,context_data):
                    #gets the quesion
            context_data['question'] = Question.objects.filter(
                questionnaire=g.questionnaire)[g.questionNo-1]
            #number of the question
            context_data['questionNo'] = int(g.questionNo)
            #answers of the question
            context_data['answers'] = Answer.objects.filter(
                question=context_data['question'])
            context_data['answer_list'] = []

            #and makes a new key on context_data
            try:
                
                #that will check if it exists
                if context_data['answers'][0]:
                    #and will apend on the new key list a dict
                    #with the answers and the class
                    context_data['answer_list'].append({'answer' : context_data['answers'][0],
                                                        'class' : " text-white bg-danger "})

                if context_data['answers'][1]:
                    context_data['answer_list'].append({'answer' : context_data['answers'][1],
                                                        'class' : " text-white bg-primary "})

                if context_data['answers'][2]:
                    context_data['answer_list'].append({'answer' : context_data['answers'][2],
                                                        'class' : " text-white bg-success",
                                                        'extra' : " w-100 "})

                if context_data['answers'][3]:
                    context_data['answer_list'].append({'answer' : context_data['answers'][3],
                                                    'class' : " bg-warning"})
            except: IndexError

            return context_data
    

#view set of the participant
class ParticipantViewSet(viewsets.ModelViewSet):
    queryset = Participant.objects.all()
    serializer_class = ParticipantSerializer
    permission_classes = [AllowAny] #Redifine all methods

    #creation
    def create(self, request, *args, **kwargs):
        data = request.data
        #needs to be a real game
        if Game.objects.filter(publicId=data['game']).exists() :
           
            g = Game.objects.get(publicId=data['game'])

            #and the alias needs to be unique
            if not Participant.objects.filter(game=g,
                                              alias=data['alias']).exists():

                p = Participant.objects.create(game=g,
                                               alias=data['alias'])
                data['uuidP'] =  p.uuidP  
                data['state'] =  g.state

                serializer = self.serializer_class(data=data)
                return Response(data=serializer.initial_data, status=status.HTTP_201_CREATED)
            
        return Response(status=status.HTTP_403_FORBIDDEN)
    
    def list(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_400_BAD_REQUEST)
    
    def retrieve(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_400_BAD_REQUEST)
        
    def update(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)

    def partial_update(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)

    def destroy(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)

#game view set
class GameViewSet(viewsets.ModelViewSet):
    queryset = Game.objects.all()
    serializer_class = GameSerializer
    lookup_field = 'publicId' 
    permission_classes = [AllowAny] #Redifine all methods

    
    def create(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)

    def update(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)

    def partial_update(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)

    def destroy(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)


    def list(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)

    #it can get the game data 
    def retrieve(self, request, *args, **kwargs):
        
        data = {
            "publicId" : int(kwargs.get('publicId')),
            }
        
        #if it exists
        if Game.objects.filter(publicId=data['publicId']).exists():
            g = Game.objects.get(publicId=data['publicId'])
            data['state'] = int(g.state)
            data['questionNo'] = int(g.questionNo)
            q = Question.objects.filter(questionnaire=g.questionnaire)[g.questionNo-1]
            data['answers'] = int(Answer.objects.filter(question=q).count())
            data['countdownTime'] = int(g.countdownTime)
            serializer = self.serializer_class(data=data)
            return Response(data=serializer.initial_data, status=status.HTTP_200_OK)
            

        return Response(status=status.HTTP_400_BAD_REQUEST)

#guess view set
class GuessViewSet(viewsets.ModelViewSet):
    queryset = Guess.objects.all()
    serializer_class = GuessSerializer
    
    def retrieve(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)

    #it can create the guess    
    def create(self, request, *args, **kwargs):
        data = request.data
        
        #if the game exists
        if Game.objects.filter(publicId=data['game']).exists():
            g = Game.objects.get(publicId=data['game'])
            #the state its question
            if g.state == 2:
                #the participant exists
                if Participant.objects.filter(uuidP=data['uuidp']).exists():
                    p = Participant.objects.get(uuidP=data['uuidp'])
                    q = Question.objects.filter(questionnaire=g.questionnaire)
                    a = Answer.objects.filter(question=q[g.questionNo-1])
                    #the answer aswell
                    if a.exists():
                        #and the guess doesnt
                        if not Guess.objects.filter(game=g,
                                                participant=p,
                                                question=q[g.questionNo-1]).exists():

                            Guess.objects.create(game=g,
                                                        participant=p,
                                                        question=q[g.questionNo-1],
                                                        answer=a[data['answer']])

                            return Response(status=status.HTTP_201_CREATED)
                    else:
                        return Response(data="You already answered this question", status=status.HTTP_403_FORBIDDEN)
            
            else:
                return Response(data="wait until the question is shown", status=status.HTTP_403_FORBIDDEN)
            
        return Response(status=status.HTTP_403_FORBIDDEN)

    def update(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)

    def partial_update(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)

    def destroy(self, request, *args, **kwargs):
        return Response(data="Authentication credentials were not provided.", status=status.HTTP_403_FORBIDDEN)


class UserViewSet(viewsets.ModelViewSet):
    queryset = User.objects.all()
    serializer_class = UserSerializer



class AnswerViewSet(viewsets.ModelViewSet):
    queryset = Answer.objects.all()
    serializer_class = AnswerSerializer
