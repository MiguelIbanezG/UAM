from django.db import models

# Create your models here.


class canal (models.Model):
    '''id = models.AutoField(primary_key=True,
                          unique=True)'''
    
    nombreCanal = models.CharField(max_length=200,
                                     blank=False,
                                     null=False)

    def __str__(self) -> str:
        return f'{self.id}'+ " - Nombre: " + f'{self.nombreCanal}'

class usuario (models.Model):
    '''id = models.AutoField(primary_key=True,
                          unique=True)'''
    
    nombreUsuario = models.CharField(max_length=200,
                                     blank=False,
                                     null=False)


    def __str__(self) -> str:
        return f'{self.id}'+ " - Nombre: " + f'{self.nombreUsuario}'
    

class suscripcion (models.Model):
    '''id = models.AutoField(primary_key=True,
                          unique=True)'''
    
    canal = models.ForeignKey('canal',
                              on_delete=models.CASCADE)
  
    usuario = models.ForeignKey('usuario',
                                on_delete=models.CASCADE)

    fechaDeSuscripcion = models.DateTimeField(auto_now_add=True)

    def __str__(self) -> str:
        return str(f'{self.id}'+ " - " +
                   f'{self.usuario.nombreUsuario}'+
                   " Suscrito a " + f'{self.canal.nombreCanal}' +
                   " el " + f'{self.fechaDeSuscripcion}')
    
