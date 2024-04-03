from django.contrib import admin

# Register your models here.
from .models import Pista, Socio, Reserva
# Register your models here.
admin.site.register(Socio)
admin.site.register(Pista)
admin.site.register(Reserva)
