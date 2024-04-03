from django.db import models
from django.contrib.auth.models import AbstractUser
import uuid
import random
from django.urls import reverse


class User(AbstractUser):
    pass


#author: Sergio Hidalgo
class Questionnaire(models.Model):
    id = models.AutoField(
        primary_key=True,
        help_text='Unique ID for the Questionnarie')
    title = models.CharField(
        max_length=200)
    created_at = models.DateTimeField(
        auto_now_add=True)
    updated_at = models.DateTimeField(
        auto_now=True, null=True)
    user: User = models.ForeignKey(
        'User', on_delete=models.CASCADE,
        null=False, blank=False)

    def get_absolute_url(self):
        """Returns the URL to access a detail
        record for this book."""
        return reverse('questionnaire-detail',
                       args=[str(self.id)])

    def __str__(self):
        return (f'{self.title} - ' +
                f'By {self.user.username}')

    class Meta:
        ordering = ['-updated_at']


#author: Sergio Hidalgo
class Question(models.Model):
    id = models.AutoField(primary_key=True,
                          help_text='Unique ID for the Question')
    question = models.CharField(
        max_length=200)
    questionnaire: Questionnaire = models.ForeignKey('Questionnaire',
                                                     on_delete=models.CASCADE,
                                                     null=False, blank=False)
    created_at = models.DateTimeField(
        auto_now_add=True)
    updated_at = models.DateTimeField(
        auto_now=True, null=True)
    answerTime = models.IntegerField(default=20,
        blank=True)

    def save(self, *args, **kwargs):

        if not self.answerTime:
            self.answerTime = 10

        super(Question, self).save(
            *args, **kwargs)

    def __str__(self):
        return (f'{self.question} - Time: {self.answerTime}s')

    class Meta:
        ordering = ["created_at"] 

#author: Sergio Hidalgo
class Answer(models.Model):
    id = models.AutoField(primary_key=True,
                          help_text='Unique ID for the Answer')

    answer = models.CharField(max_length=200)
    question: Question = models.ForeignKey('Question',
                                           on_delete=models.CASCADE,
                                           null=False, blank=False)

    correct = models.BooleanField()

    def __str__(self):

        return (f'Answer: {self.answer}'
                f' - {self.correct}')


#author: Sergio Hidalgo
class Game(models.Model):
    id = models.AutoField(primary_key=True,
                          help_text='Unique ID for the Game')

    questionnaire: Questionnaire = models.ForeignKey('Questionnaire',
                                                     on_delete=models.CASCADE,
                                                     null=False,
                                                     blank=False)
    created_at = models.DateTimeField(auto_now_add=True)
    GAME_STATE = (
        (1, 'WAITING'),
        (2, 'QUESTION'),
        (3, 'ANSWER'),
        (4, 'LEADERBOARD'),
    )
    state = models.IntegerField(choices=GAME_STATE,
                                blank=False,
                                default=1,
                                help_text='Game state',
                                )
    publicId = models.IntegerField(blank=True,
                                   unique=True)
    countdownTime = models.IntegerField(default=10)
    questionNo = models.IntegerField(default=1)

    def save(self, *args, **kwargs):
        if self.publicId == None:
            self.publicId = int(
                random.randint(0, 1000000))
        super(Game, self).save(
            *args, **kwargs)

    def __str__(self):

        return (f'Questionnaire: - {self.questionnaire.title} ' +
                f'- PublicId {self.publicId} ' +
                f'- Question: {self.questionNo} ' +
                f'- Countdown: {self.countdownTime} s')


#author: Sergio Hidalgo
class Participant(models.Model):
    id = (models.
                      AutoField(primary_key=True,
                                help_text='Unique ID for the Participant'))

    game: Game = models.ForeignKey('Game',
                                   on_delete=models.CASCADE,
                                                     null=False,
                                                     blank=False)

    alias = models.CharField(max_length=200)

    points = models.IntegerField(default=0)

    uuidP = models.UUIDField(default=uuid.uuid4)

    def __str__(self):

        return (f'{int(self.id)} - Player: ' +
                f'{self.alias} - Game: ' +
                f'{int(self.game.id)}' +
                f'- Points: {self.points} - ' +
                f'UUidP: {self.uuidP}')


#author: Sergio Hidalgo
class Guess(models.Model):
    id = models.AutoField(
        primary_key=True,
        help_text='Unique ID for the Guess')

    participant: Participant = models.ForeignKey(
        'Participant',
        on_delete=models.CASCADE,
        null=False,
        blank=False)

    game: Game = models.ForeignKey(
        'Game',
        on_delete=models.CASCADE,
        null=False,
        blank=False)

    question: Question = models.ForeignKey(
        'Question',
        on_delete=models.CASCADE,
        null=False,
        blank=False)

    answer: Answer = models.ForeignKey(
        'Answer',
        on_delete=models.CASCADE,
        null=False,
        blank=False)

    def save(self, *args, **kwargs):

        if self.answer.correct is True:
            self.participant.points += 1
            p = Participant.objects.filter(id=self.participant.id)
            p.update(points=self.participant.points)
        super(Guess, self).save(*args, **kwargs)

    def __str__(self):

        return (f'{int(self.id)} - ' +
                f'Guess from: {self.participant.alias} ' +
                f'- To: {self.question.question}' +
                f' - Is: {self.answer.answer}' +
                f' - Which is: {self.answer.correct}' +
                f'[Game: {self.game.publicId}]')



