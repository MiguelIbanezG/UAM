"""kahootclone URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/3.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path

from django.conf import settings
from django.conf.urls.static import static

from django.urls import include

from django.views.generic import RedirectView

from rest_framework import routers
from models import views

router = routers.DefaultRouter()

#router.register('users', views.UserViewSet)
#router.register('answers', views.AnswerViewSet)
router.register('participant', views.ParticipantViewSet)
router.register('games', views.GameViewSet)
router.register('guess', views.GuessViewSet)


urlpatterns = [
    path('admin/', admin.site.urls),
    path('', RedirectView.as_view(url='/models/', permanent=True)),
    path('home/', RedirectView.as_view(url='/models/', permanent=True)),

]

urlpatterns += static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)

urlpatterns += [
    path('accounts/', include('django.contrib.auth.urls')),

]


urlpatterns += [
    path('models/', include('models.urls')),
]

urlpatterns += [
    path('api/', include(router.urls)),
]

