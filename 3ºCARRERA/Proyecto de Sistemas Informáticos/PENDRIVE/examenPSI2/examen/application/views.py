from multiprocessing import context
from django.http import HttpResponse
from django.shortcuts import get_object_or_404, render
from django.urls import reverse_lazy
from flask import request
import pkg_resources
from .models import Socio, Pista, Reserva


# Create your views here.



def socio(request, PK):
    socio = get_object_or_404(Socio, pk=PK)
    reservas = Reserva.objects.filter(socio=socio)
    context = {'nombreSocio': socio.nombreSocio, 'fechaDeSuscripcion': socio.fechaDeSuscripcion, 'reservas': reservas}
    return HttpResponse(render(request, 'socio_detail.html', context))