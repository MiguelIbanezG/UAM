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
import os

from django.core.management.base import BaseCommand
from application.models import canal 
from application.models import usuario
from application.models import suscripcion

import datetime

import os
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'project.settings')

import django
django.setup()

from django.utils import timezone
import pytz

# The name of this class is not optional must be Command
# otherwise manage.py will not process it properly
class Command(BaseCommand):
    # helps and arguments shown when command python manage.py help populate
    # is executed.
    help = """populate kahootclone database
           """
    
    users = []
    chanels = []
    subscriptions = []
    # if you want to pass an argument to the function
    # uncomment this line
    # def add_arguments(self, parser):
    #    parser.add_argument('publicId',
    #        type=int,
    #        help='game the participants will join to')
    #    parser.add_argument('sleep',
    #        type=float,
    #        default=2.,
    #        help='wait this seconds until inserting next participant')

    def __init__(self, sneaky=True, *args, **kwargs):
        super().__init__(*args, **kwargs)
        # "if 'RENDER'" allows you to deal with different
        # behaviour in render.com and locally
        # That is, we check a variable ('RENDER')
        # that is only defined in render.com
        if 'RENDER' in os.environ:
            pass
        else:
            pass

        self.NUMBERUSERS = 100
        self.NUMBERCHANELS = 30
        self.NUMBERSUBS = 40

    # handle is another compulsory name, do not change it"
    # handle function will be executed by 'manage populate'
    def handle(self, *args, **kwargs):
        "this function will be executed by default"

        self.cleanDataBase()   # clean database
        self.usuario()  # create users
        self.canal()  # create canal
        self.suscripcion()  # create suscripcion

    def cleanDataBase(self):
        # delete all models stored (clean table)
        usuario.objects.all().delete()
        canal.objects.all().delete()
        suscripcion.objects.all().delete()
        print("clean Database")

    def usuario(self):
        " Insert users"
        print("Users")
            
        userdb = usuario(id=1001,
                        nombreUsuario='antonio2985')
        self.users.append(userdb)
        userdb.save()

        userdb = usuario(id=1002,
                        nombreUsuario='respetaCamiones124')
        self.users.append(userdb)
        userdb.save()

        userdb = usuario(id=1003,
                        nombreUsuario='asierUR')
        self.users.append(userdb)
        userdb.save()
    
    
    
    def canal(self):
        " Insert canales"
        print("Canales")
        
            
        canaldb = canal(id=1001,
                        nombreCanal='elxokasTV')
        self.chanels.append(canaldb)
        canaldb.save()

        canaldb = canal(id=1002,
                        nombreCanal='ibai')
        self.chanels.append(canaldb)
        canaldb.save()

        canaldb = canal(id=1003,
                        nombreCanal='playz')
        self.chanels.append(canaldb)
        canaldb.save()

        
    def suscripcion(self):
        " Insert canales"
        print("Canales")

        timezone.now()
        
            
        subdb = suscripcion(id=1001,
                            canal=self.chanels[0],
                            usuario=self.users[0],
                            fechaDeSuscripcion=datetime.datetime(2023, 4, 5,tzinfo=pytz.UTC))

        subdb.save()

        subdb = suscripcion(id=1002,
                            canal=self.chanels[0],
                            usuario=self.users[1],
                            fechaDeSuscripcion=datetime.datetime(2023, 4, 11,tzinfo=pytz.UTC))
        subdb.save()

        subdb = suscripcion(id=1003,
                            canal=self.chanels[2],
                            usuario=self.users[2],
                            fechaDeSuscripcion=datetime.datetime(2023, 4, 12,tzinfo=pytz.UTC))
        subdb.save()


