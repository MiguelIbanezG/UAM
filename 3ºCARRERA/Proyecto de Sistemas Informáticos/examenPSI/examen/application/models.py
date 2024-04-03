# Create your models here.
from django.db import models


class Canal(models.Model):
    '''id = models.AutoField(primary_key=True)'''
    nombreCanal = models.CharField(max_length=200)

    def __str__(self):
        """String for representing the Model object."""
        return self.nombreCanal
    
    '''def __str__(self) -> str:
        return f'{self.id}'+ " - Nombre: " + f'{self.nombreCanal}'''

class Usuario(models.Model):
    nombreUsuario = models.CharField(max_length=200)

    def __str__(self):
        """String for representing the Model object."""
        return self.nombreUsuario
    

class Suscripcion(models.Model):
    canal = models.ForeignKey(Canal, on_delete=models.CASCADE)
    usuario = models.ForeignKey(Usuario, on_delete=models.CASCADE)
    '''usuario = models.ForeignKey('usuario',
                                on_delete=models.CASCADE)'''
    fechaDeSuscripcion = models.DateTimeField(auto_now_add=True)
    '''fechaDeSuscripcion = models.DateTimeField'''

    def __str__(self) -> str:
        return str(f'{self.id}'+ " - " +
                   f'{self.usuario.nombreUsuario}'+
                   " Suscrito a " + f'{self.canal.nombreCanal}' +"  "
                   f'{self.fechaDeSuscripcion}')


    
    

