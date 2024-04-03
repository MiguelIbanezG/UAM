# Generated by Django 3.2.1 on 2023-05-08 21:17

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('application', '0002_alter_suscripcion_fechadesuscripcion'),
    ]

    operations = [
        migrations.AlterField(
            model_name='canal',
            name='nombreCanal',
            field=models.CharField(max_length=200),
        ),
        migrations.AlterField(
            model_name='suscripcion',
            name='fechaDeSuscripcion',
            field=models.DateTimeField(auto_now_add=True),
        ),
        migrations.AlterField(
            model_name='usuario',
            name='nombreUsuario',
            field=models.CharField(max_length=200),
        ),
    ]
