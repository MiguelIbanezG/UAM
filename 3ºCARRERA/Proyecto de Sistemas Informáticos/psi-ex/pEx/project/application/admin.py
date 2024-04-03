from django.contrib import admin

from . import models


admin.site.register(models.canal)
admin.site.register(models.usuario)
admin.site.register(models.suscripcion)