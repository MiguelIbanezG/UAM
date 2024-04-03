from django import forms
from .models import Canal

class CanalCreateForm(forms.ModelForm):
    class Meta:
        model = Canal
        fields = ['nombreCanal']