
from django.urls import path
from django.urls import re_path
from . import views

urlpatterns = [
    path('canal/<int:PK>/', views.canal, name='canal'),
]


