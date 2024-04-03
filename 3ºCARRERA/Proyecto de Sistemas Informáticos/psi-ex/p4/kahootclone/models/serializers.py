from .models import User
from .models import Answer
from .models import Game
from .models import Participant
from .models import Guess


from rest_framework import serializers



class ParticipantSerializer(serializers.ModelSerializer):
    publicId = serializers.IntegerField()
    
    class Meta:
        model = Participant
        fields = ['id', 'alias', 'uuidP', 'publicId']


class GameSerializer(serializers.ModelSerializer):
    questionnaire = serializers.IntegerField()
    
    class Meta:
        model = Game
        fields = ['id', 'state', 'questionnaire', 
                  'publicId', 'questionNo']


class GuessSerializer(serializers.ModelSerializer):
    class Meta:
        model = Guess
        fields = ['id', 'participant', 'game', 'question', 'answer']



class UserSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ['id', 'username', 'email', 'url']



class AnswerSerializer(serializers.ModelSerializer):
    class Meta:
        model = Answer
        fields = ['id', 'answer', 'question', 'correct', 'url']


