from django.test import TestCase, Client
from .models import usuario
from .models import canal
from .models import suscripcion
from django.urls import reverse
from datetime import date

# Create your tests here.
class TestViews(TestCase):

    def setUp(self):
        self.client = Client()

    def test_canal_view(self):
        # borra todos los canales, usuarios y suscripciones
        canal.objects.all().delete()
        usuario.objects.all().delete()
        suscripcion.objects.all().delete()

        # crea los objetos necesarios
        user_jordi = usuario.objects.create(id=1001, nombreUsuario='jordi')
        user_nacho = usuario.objects.create(id=1002, nombreUsuario='nacho')
        canal_aux = canal.objects.create(id=1001, nombreCanal='wildproject')
        suscripcion.objects.create(usuario=user_jordi, canal_aux=canal, fechaDeSuscripcion=date(2023, 5, 8))
        suscripcion.objects.create(usuario=user_nacho, canal_aux=canal, fechaDeSuscripcion=date(2023, 5, 7))

        # accede a la vista de canal con id 1001
        response = self.client.get(reverse('canal', args=[1001]))

        # comprueba que las suscripciones son correctas
        suscripciones = response.context['suscripciones']
        self.assertEqual(len(suscripciones), 2)
        self.assertEqual(suscripciones[0].usuario, user_jordi)
        self.assertEqual(suscripciones[1].usuario, user_nacho)