from django.db import models
from django.contrib.auth.models import AbstractUser
import uuid
import random
from django.urls import reverse


class User(AbstractUser):
    pass


class Questionnaire(models.Model):
    id = models.AutoField(primary_key=True,
                          help_text='Unique ID for the Questionnarie')
     
    title = models.CharField(max_length=200)

    created_at = models.DateTimeField(auto_now_add=True)
    
    updated_at = models.DateTimeField(auto_now=True, null=True)

    
    user:User = models.ForeignKey('User', on_delete=models.RESTRICT, null=True)

    def get_absolute_url(self):
        """Returns the URL to access a detail record for this book."""
        return reverse('questionnaire-detail', args=[str(self.id)])

    def __str__(self):
        return (f'{self.title} - '+
                f'By {self.user.username}')
    
    class Meta:
        ordering = ['-updated_at']
    

class Question(models.Model):
    id = models.AutoField(primary_key=True, 
                          help_text='Unique ID for the Question')
 
    question = models.CharField(max_length=200,
                            help_text='The Question')

    questionnaire:Questionnaire = models.ForeignKey('Questionnaire', on_delete=models.RESTRICT, null=False)
   
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True, null=True)
    
    answerTime = models.IntegerField(blank=True)

        
    def save(self, *args, **kwargs):

        if not self.answerTime:
            self.answerTime = 10


        super(Question, self).save(*args, **kwargs)

    def __str__(self):
        return (f'{self.question} - Time: {self.answerTime}s')
    


class Answer(models.Model):
    id =  models.AutoField(primary_key=True,
                          help_text='Unique ID for the Answer')
    
    answer = models.CharField(max_length=200,
                            help_text='The Answer')
    question:Question = models.ForeignKey('Question', on_delete=models.RESTRICT, null=False)
    
    correct = models.BooleanField()

   
    def __str__(self):

        return (f'Answer: {self.answer}' 
                f' - {self.correct}')


class Game(models.Model):
    id =  models.AutoField(primary_key=True,
                          help_text='Unique ID for the Game')
    
    questionnaire:Questionnaire = models.ForeignKey('Questionnaire', on_delete=models.RESTRICT, null=False)
    
    created_at = models.DateTimeField(auto_now_add=True)
    
    
    GAME_STATE = (
        (1, 'WAITING'),
        (2, 'QUESTION'),
        (3, 'ANSWER'),
        (4, 'LEADERBOARD'),
    )

    state = models.IntegerField(
        choices=GAME_STATE,
        blank=False,
        default=1,
        help_text='Game state',
    )
    
    publicId = models.IntegerField(blank=True, unique=True)
    
    countdownTime = models.IntegerField()
    
    questionNo = models.IntegerField()

    def save(self, *args, **kwargs):

        self.publicId = int(random.randint(0, 1000000))

        super(Game, self).save(*args, **kwargs)


    def __str__(self):

        return (f'Questionnaire: '+ 
                f'{self.questionnaire.title} ' + 
                f'- PublicId {self.publicId} - Question: {self.questionNo} '+
                f'- Ends in {self.countdownTime}')



class Participant(models.Model):
    participant_id = models.AutoField(primary_key=True,
                          help_text='Unique ID for the Participant')
    
    game:Game = models.ForeignKey('Game', on_delete=models.RESTRICT, null=False)
    
    alias = models.CharField(max_length=200,
                            help_text='Player')
    
    points = models.IntegerField(default=0)
    
    uuidP = models.UUIDField(default=uuid.uuid4)


    def __str__(self):

        return (f'{int(self.participant_id)} - Player: '+ 
                f'{self.alias} - Game: ' + 
                f'{int(self.game.id)}' + 
                f'- Points: {self.points} - '+
                f'UUidP: {self.uuidP}')


class Guess(models.Model):
    id = models.AutoField(primary_key=True, 
                          help_text='Unique ID for the Guess')
    
    participant:Participant = models.ForeignKey('Participant', 
                                                editable=False, 
                                                on_delete=models.RESTRICT, 
                                                null=False)
    
    game:Game = models.ForeignKey('Game', 
                                  editable=False,
                                  on_delete=models.RESTRICT, 
                                  null=False)
    
    question:Question = models.ForeignKey('Question', 
                                          editable=False,
                                          on_delete=models.RESTRICT, 
                                          null=False)
    
    answer:Answer = models.ForeignKey('Answer',
                                      editable=False,
                                      on_delete=models.RESTRICT, 
                                      null=False)

    def save(self, *args, **kwargs):

        if self.answer.correct is True:
            self.participant.points+=1 

        super(Guess, self).save(*args, **kwargs)

    def __str__(self):

        return (f'{int(self.id)} - '
                + f'Guess from: {self.participant.alias} - To: '+
                f'{self.question.question} - Is: {self.answer.answer}'+
                f' - Which is: {self.answer.correct} [Game: {self.game.publicId}]')