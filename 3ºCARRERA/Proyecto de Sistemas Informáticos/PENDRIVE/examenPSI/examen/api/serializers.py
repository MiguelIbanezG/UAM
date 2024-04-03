from rest_framework import serializers
from .models import Canal, Suscripcion, Usuario

class CanalSerializer(serializers.ModelSerializer):
    class Meta:
        model = Canal
        fields = '__all__'

class SuscripcionSerializer(serializers.ModelSerializer):
    class Meta:
        model = Suscripcion
        fields = '__all__'

class UsuarioSerializer(serializers.ModelSerializer):
    class Meta:
        model = Usuario
        # fields = ['id', 'nombre', 'descripcion', 'precio']
        fields = '__all__'
