from .models import Questionnaire, User, Question, Participant
from django.contrib.auth.forms import UserCreationForm
from django import forms


#author: Sergio Hidalgo
class SignUpForm(UserCreationForm):
    class Meta:
        model = User
        fields = ('username', 'first_name', 'last_name',
                  'email', 'password1', 'password2', )


#author: Sergio Hidalgo
class QuestionnaireCreateForm(forms.ModelForm):

    class Meta:
        model = Questionnaire
        fields = ('title', )
        labels = {
        }
        widgets = {
            'title': forms.TextInput(),
        }



#author: Sergio Hidalgo
class QuestionCreateForm(forms.ModelForm):

    class Meta:
        model = Question
        fields = ('question', 'answerTime', )
        labels = {
        }
        widgets = {
            'question': forms.TextInput(),
            'answerTime': forms.NumberInput(),
        }


#author: Sergio Hidalgo
class ParticipantJoinForm(forms.ModelForm):

    publicId = forms.IntegerField()

    class Meta:
        model = Participant
        fields = ('alias', )
        labels = {
        }
        widgets = {
            'alias': forms.TextInput(),
            'publicId': forms.NumberInput(),
        }
