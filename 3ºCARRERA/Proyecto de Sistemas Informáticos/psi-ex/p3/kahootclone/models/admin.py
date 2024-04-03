from django.contrib import admin

# Register your models here.
from .models import User, Questionnaire, Question 
from .models import Answer, Game, Participant, Guess

admin.site.register(User)
admin.site.register(Questionnaire)
admin.site.register(Question)
admin.site.register(Answer)
admin.site.register(Game)
admin.site.register(Participant)
admin.site.register(Guess)