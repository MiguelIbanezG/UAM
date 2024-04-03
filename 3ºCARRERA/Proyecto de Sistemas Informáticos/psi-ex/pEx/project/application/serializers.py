from .models import usuario
from .models import canal
from .models import suscripcion


from rest_framework import serializers



class UsuarioSerializer(serializers.ModelSerializer):
    
    class Meta:
        model = usuario
        fields = '__all__'


class CanalSerializer(serializers.ModelSerializer):
    
    class Meta:
        model = canal
        fields = '__all__'


class SuscripcionSerializer(serializers.ModelSerializer):
    
    class Meta:
        model = suscripcion
        fields = '__all__'

