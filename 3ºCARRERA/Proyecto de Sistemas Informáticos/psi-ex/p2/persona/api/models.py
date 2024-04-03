from django.db import models
# Create your models here.

class Persona(models.Model):
    # id = models.IntegerField(primary_key=True)
    nombre = models.CharField(max_length=200)
    apellido = models.CharField(max_length=200)
    email = models.CharField(max_length=200)

    

    class Meta:
        ordering = ['id']

  