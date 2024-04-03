# Create your models here.
from django.db import models


class Canal(models.Model):
    nombreCanal = models.CharField(max_length=100)

    def __str__(self):
        """String for representing the Model object."""
        return self.nombreCanal

class Usuario(models.Model):
    nombreUsuario = models.CharField(max_length=100)

    def __str__(self):
        """String for representing the Model object."""
        return self.nombreUsuario
    

class Suscripcion(models.Model):
    canal = models.ForeignKey(Canal, on_delete=models.CASCADE)
    usuario = models.ForeignKey(Usuario, on_delete=models.CASCADE)
    fechaDeSuscripcion = models.DateField(auto_now_add=True)

