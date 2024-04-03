from django.contrib import admin
from django.urls import path, include
from api import views

from rest_framework import routers

router = routers.DefaultRouter()
# En el router vamos agnadiendo los endpoints a los viewsets
router.register('personas', views.PersonaViewSet)
urlpatterns = [
path('api/v1/', include(router.urls)),
path('admin/', admin.site.urls),
]
