from django.contrib import admin
from .models import Canal, Usuario, Suscripcion
# Register your models here.

admin.site.register(Canal)
admin.site.register(Usuario)
admin.site.register(Suscripcion)

'''from . import models


admin.site.register(models.canal)
admin.site.register(models.usuario)
admin.site.register(models.suscripcion)'''