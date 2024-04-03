from django.test import TestCase

# Create your tests here.
from django.test import TestCase, Client
from django.urls import reverse
from datetime import date

from .models import Canal, Usuario, Suscripcion


class TestViews(TestCase):

    def setUp(self):
        self.client = Client()

    def test_canal_view(self):
        # borra todos los canales, usuarios y suscripciones
        Canal.objects.all().delete()
        Usuario.objects.all().delete()
        Suscripcion.objects.all().delete()

        # crea los objetos necesarios
        user_jordi = Usuario.objects.create(id=1001, nombreUsuario='jordi')
        user_nacho = Usuario.objects.create(id=1002, nombreUsuario='nacho')
        canal = Canal.objects.create(id=1001, nombreCanal='wildproject')
        Suscripcion.objects.create(usuario=user_jordi, canal=canal, fechaDeSuscripcion=date(2023, 5, 8))
        Suscripcion.objects.create(usuario=user_nacho, canal=canal, fechaDeSuscripcion=date(2023, 5, 7))

        # accede a la vista de canal con id 1001
        response = self.client.get(reverse('canal', args=[1001]))

        # comprueba que las suscripciones son correctas
        suscripciones = response.context['suscripciones']
        self.assertEqual(len(suscripciones), 2)
        self.assertEqual(suscripciones[0].usuario, user_jordi)
        self.assertEqual(suscripciones[1].usuario, user_nacho)