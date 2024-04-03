"""
Script intended to populate the DB
Created by Seregio
EPS-UAM 2023
"""

import os
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'persona.settings')

import django
django.setup()
from api.models import Persona


def populate():

    personas = [
        {
            'nombre': 'Jon',
            'apellido': 'Nieve',
            'email': 'jon@email.com',
        },
        {
            'nombre': 'Tyrion',
            'apellido': 'Lannister',
            'email': 'tyrion@email.com',
        },
        {
            'nombre': 'Daenerys',
            'apellido': 'Targaryen',
            'email': 'daenerys@email.com',
        },
    ]

    for p in personas:
        auth = Persona(nombre=p['nombre'], apellido=p['apellido'], email=p['email'])
        auth.save()


if __name__ == '__main__':
    print("Starting catalog population script...")
    populate()
    print("Done!")
