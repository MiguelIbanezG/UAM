import datetime
import os
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'examen.settings')

import django
django.setup()


from application.models import Pista, Reserva, Socio

def main():
    
    socio_01 = Socio(id=1001, nombreSocio='socio_01',fechaDeSuscripcion= '2019-04-08')
    socio_02 = Socio(id=1002, nombreSocio='socio_02',fechaDeSuscripcion= '2020-07-14')
    socio_03 = Socio(id=1003, nombreSocio='socio_03', fechaDeSuscripcion='2021-03-08')
    socio_01.save()
    socio_02.save()
    socio_03.save()

    cesped = Pista(id=1001, tipoSuperficie='cesped artificial', enMantenimiento=False)
    resina = Pista(id=1002, tipoSuperficie='resina sintetica', enMantenimiento=False)
    cemento = Pista(id=1003, tipoSuperficie='cemento', enMantenimiento=True)
    cesped.save()
    resina.save()
    cemento.save()

    reserva_01 = Reserva(socio=socio_01, pista=cesped, fechaReserva='2021-03-21', horaReserva=12 )
    reserva_02 = Reserva(socio=socio_02, pista=cesped, fechaReserva='2021-07-21', horaReserva=19 )
    reserva_03 = Reserva(socio=socio_03, pista=resina, fechaReserva='2021-05-25', horaReserva=17)
    reserva_04 = Reserva(socio=socio_02, pista=cemento, fechaReserva='2021-08-25', horaReserva=22)
    reserva_01.save()
    reserva_02.save()
    reserva_03.save()
    reserva_04.save()
