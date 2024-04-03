from django.urls import path
from django.urls import include
from django.contrib.auth import views as auth_views
from django.contrib.auth.forms import UserCreationForm
from . import views

urlpatterns = []

urlpatterns = [
    path('', views.HomeView.as_view(), name='home'),
    path('home', views.HomeView.as_view(), name='home'),
]


urlpatterns += [
    path('login/',
         auth_views.LoginView.as_view(), name='login'),
    path('logout/',
         auth_views.LogoutView.as_view(), name='logout'),
    path('signup/',
         views.signup, name='signup'),
]

urlpatterns += [
    
     path('home/latest_questionnaire_list', 
          views.HomeView.as_view(),
          name='home'),

    path('services/questionnaire/<int:pk>',
         views.QuestionnaireDetailView.as_view(),
         name='questionnaire-detail'),

    path('services/questionnairelist',
         views.QuestionnaireListView.as_view(),
         name='questionnaire-list'),

    path('services/questionnaireremove/<int:pk>',
         views.QuestionnaireRemoveView.as_view(),
         name='questionnaire-remove'),

    path('services/questionnaireupdate/<int:pk>',
         views.QuestionnaireUpdateView.as_view(),
         name='questionnaire-update'),

    path('services/questionnairecreate/',
         views.QuestionnaireCreateView.as_view(),
         name='questionnaire-create'),


    path('services/question/<int:pk>',
         views.QuestionDetailView.as_view(),
         name='question-detail'),

    path('services/questionremove/<int:pk>',
         views.QuestionRemoveView.as_view(),
         name='question-remove'),

     path('services/questionupdate/<int:pk>',
         views.QuestionUpdateView.as_view(),
         name='question-update'),

    path('services/questioncreate/<int:questionnaireid>',
         views.QuestionCreateView.as_view(),
         name='question-create'),

     path('services/answercreate/<int:questionid>',
         views.AnswerCreateView.as_view(),
         name='answer-create'),

    path('services/answerremove/<int:pk>',
         views.AnswerRemoveView.as_view(),
         name='answer-remove'),

    path('services/answerupdate/<int:pk>',
         views.AnswerUpdateView.as_view(),
         name='answer-update'),


    path('services/gamecreate/<int:pk>',
         views.GameCreateView.as_view(),
         name='game-create'),


]
