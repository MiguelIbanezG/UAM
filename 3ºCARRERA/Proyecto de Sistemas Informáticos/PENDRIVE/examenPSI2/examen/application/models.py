from django.db import models

# Create your models here.
from django.db import models
    
class Socio(models.Model):
    id = models.AutoField(primary_key=True)
    nombreSocio = models.CharField(max_length=100)
    fechaDeSuscripcion = models.DateField(auto_now_add=True)

    def __str__(self):
        """String for representing the Model object."""
        return self.nombreSocio

class Pista(models.Model):
    id = models.AutoField(primary_key=True)
    tipoSuperficie = models.CharField(max_length=100)
    enMantenimiento = models.BooleanField()

    def __str__(self):
        """String for representing the Model object."""
        return self.tipoSuperficie
    
class Reserva(models.Model):
    socio = models.ForeignKey(Socio, on_delete=models.CASCADE)
    pista = models.ForeignKey(Pista, on_delete=models.CASCADE)
    fechaReserva = models.DateField(auto_now_add=True)
    horaReserva = models.DateTimeField(auto_now_add=True)