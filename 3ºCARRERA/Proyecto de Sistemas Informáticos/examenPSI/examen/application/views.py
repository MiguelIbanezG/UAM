import genericpath

from django.http import HttpResponse
from .models import Canal, Suscripcion, Usuario

# Create your views here.

from django.shortcuts import render, get_object_or_404


def canal(request, PK):
    canal = get_object_or_404(Canal, pk=PK)
    suscripciones = Suscripcion.objects.filter(canal=canal)
    context = {'nombreCanal': canal.nombreCanal, 'suscripciones': suscripciones}
    return HttpResponse(render(request, 'canal_detail.html', context))