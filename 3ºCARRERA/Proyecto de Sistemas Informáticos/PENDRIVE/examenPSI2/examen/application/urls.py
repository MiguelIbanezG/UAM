from django.urls import path
from django.urls import re_path
from . import views
from django.urls import path
from django.urls import include
from . import views

urlpatterns = [
    path('socio/<int:PK>/', views.socio, name='socio'),
]


