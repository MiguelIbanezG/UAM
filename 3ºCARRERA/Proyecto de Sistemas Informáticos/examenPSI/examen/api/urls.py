from django.urls import path
from django.urls import include
from django.contrib.auth import views as auth_views
from django.contrib.auth.forms import UserCreationForm
from . import views



urlpatterns = [
    path('canal/<int:PK>/', views.canal, name='canal'),
]

