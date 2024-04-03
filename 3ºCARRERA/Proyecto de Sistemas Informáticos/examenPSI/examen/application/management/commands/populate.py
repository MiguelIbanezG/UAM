# Populate database
# This file has to be placed within the
# catalog/management/commands directory in your project.
# If that directory doesn't exist, create it.
# The name of the script is the name of the custom command,
# that is, populate.py.
#
# execute python manage.py  populate
#
# use module Faker generator to generate data
# (https://zetcode.com/python/faker/)
import datetime
import os

from django.core.management.base import BaseCommand
import pytz
from application.models import Canal, Usuario, Suscripcion 


import os
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'examen.settings')

import django
django.setup()



class Command(BaseCommand):
 
    help = """populate kahootclone database
           """
    
    users = []
    chanels = []
    subscriptions = []


    def __init__(self, sneaky=True, *args, **kwargs):
        super().__init__(*args, **kwargs)
    
        if 'RENDER' in os.environ:
            pass
        else:
            pass

        self.NUMBERUSERS = 100
        self.NUMBERCHANELS = 30
        self.NUMBERSUBS = 40

    def handle(self, *args, **kwargs):
        "this function will be executed by default"

        self.cleanDataBase()   # clean database
        self.usuario()  # create users
        self.canal()  # create canal
        self.suscripcion()  # create suscripcion

    def cleanDataBase(self):
        # delete all models stored (clean table)
        Usuario.objects.all().delete()
        Canal.objects.all().delete()
        Suscripcion.objects.all().delete()
        print("clean Database")

    def usuario(self):
        " Insert users"
        print("Users")
            
        userdb = Usuario(id=1001,
                        nombreUsuario='antonio2985')
        self.users.append(userdb)
        userdb.save()

        userdb = Usuario(id=1002,
                        nombreUsuario='respetaCamiones124')
        self.users.append(userdb)
        userdb.save()

        userdb = Usuario(id=1003,
                        nombreUsuario='asierUR')
        self.users.append(userdb)
        userdb.save()
    
    
    def canal(self):
        " Insert canales"
        print("Canales")
        
            
        canaldb = Canal(id=1001,
                        nombreCanal='elxokasTV')
        self.chanels.append(canaldb)
        canaldb.save()

        canaldb = Canal(id=1002,
                        nombreCanal='ibai')
        self.chanels.append(canaldb)
        canaldb.save()

        canaldb = Canal(id=1003,
                        nombreCanal='playz')
        self.chanels.append(canaldb)
        canaldb.save()

        
    def suscripcion(self):
        " Insert suscripciones"
        print("suscripciones")
        
            
        subdb = Suscripcion(id=1001,
                            canal=self.chanels[0],
                            usuario=self.users[0],
                            fechaDeSuscripcion=datetime.datetime(2023, 4, 5,tzinfo=pytz.UTC))

        subdb.save()

        subdb = Suscripcion(id=1002,
                            canal=self.chanels[0],
                            usuario=self.users[1],
                            fechaDeSuscripcion=datetime.datetime(2023, 4, 11,tzinfo=pytz.UTC))
        subdb.save()

        subdb = Suscripcion(id=1003,
                            canal=self.chanels[2],
                            usuario=self.users[2],
                            fechaDeSuscripcion=datetime.datetime(2023, 4, 12,tzinfo=pytz.UTC))
        subdb.save()








'''
def main():

    antonio = Usuario(id=1001, nombreUsuario='antonio2985')
    respeta = Usuario(id=1002, nombreUsuario='respetaCamiones124')
    asier = Usuario(id=1003, nombreUsuario='asierUR')
    antonio.save()
    respeta.save()
    asier.save()

    xokas = Canal(id=1001, nombreCanal='elxokasTV')
    ibai = Canal(id=1002, nombreCanal='ibai')
    play = Canal(id=1003, nombreCanal='playz')
    xokas.save()
    ibai.save()
    play.save()

    suscripcion = Suscripcion(id=1001, canal=xokas, usuario=antonio, fechaDeSuscripcion='2023-04-05')
    suscripcion1 = Suscripcion(id=1002, canal=ibai, usuario=respeta, fechaDeSuscripcion='2023-04-11')
    suscripcion2 = Suscripcion(id=1003, canal=play, usuario=asier, fechaDeSuscripcion='2023-04-12')
    suscripcion.save()
    suscripcion1.save()
    suscripcion2.save()

'''
    
        
