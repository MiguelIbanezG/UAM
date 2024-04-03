
# Create your tests here.
from multiprocessing import connection
from django.test import TestCase, Client
from django.urls import reverse

from .models import Socio, Pista, Reserva
# Create your tests here.

class TestViews(TestCase):

    def setUp(self):
        self.client = Client()

    def test_canal_view(self):
        # borra todos los canales, usuarios y suscripciones
        Socio.objects.all().delete()
        Pista.objects.all().delete()
        Reserva.objects.all().delete()

        socio_01 = Socio.objects.create(id=1001, nombreSocio='Socio1',fechaDeSuscripcion= '2021-09-21')
        socio_02 = Socio.objects.create(id=1002, nombreSocio='Socio2',fechaDeSuscripcion= '2021-10-15')
        cesped = Pista.objects.create(id=1001, tipoSuperficie='cesped artificial', enMantenimiento=False)
        Reserva.objects.create(socio=socio_01, pista=cesped, fechaReserva='2021-11-08', horaReserva=10)
        Reserva.objects.create(socio=socio_02, pista=cesped, fechaReserva='2021-11-15', horaReserva=20)
        

        # accede a la vista de canal con id 1001
        response = self.client.get(reverse('socio', args=[1001]))

        # comprueba que las suscripciones son correctas
        reservas = response.context['reservas']
        self.assertEqual(len(reservas), 1)
        self.assertEqual(reservas[0].socio, socio_01)

        
