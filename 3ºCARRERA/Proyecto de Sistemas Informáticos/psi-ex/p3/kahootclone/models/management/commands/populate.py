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
from models.models import User as User
from models.models import Questionnaire as Questionnaire
from models.models import Question as Question
from models.models import Answer as Answer
from models.models import Game as Game
from models.models import Participant as Participant
from models.models import Guess as Guess

from faker import Faker
import random
from random import getrandbits

import os
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'kahootclone.settings')

import django
django.setup()

N_USERS=1000
N_GAMES=100
N_QUENARI=100
N_QUES=10
N_ASW=500



# The name of this class is not optional must be Command
# otherwise manage.py will not process it properly
class Command(BaseCommand):
    # helps and arguments shown when command python manage.py help populate
    # is executed.
    help = """populate kahootclone database
           """
    
    users = []
    questionnaires = []
    questions= []
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

        self.NUMBERUSERS = 4
        self.NUMBERQESTIONARIES = 30
        self.NUMBERQUESTIONS = 100
        self.NUMBERPARTICIPANTS = 20
        self.NUMBERANSWERPERQUESTION = 4
        self.NUMBERGAMES = 4

    # handle is another compulsory name, do not change it"
    # handle function will be executed by 'manage populate'
    def handle(self, *args, **kwargs):
        "this function will be executed by default"

        self.cleanDataBase()   # clean database
        # The faker.Faker() creates and initializes a faker generator,
        self.faker = Faker()
        self.user()  # create users
        self.questionnaire()  # create questionaries
        self.question()  # create questions
        self.answer()  # create answers
        self.game()  # create games

    def cleanDataBase(self):
        # delete all models stored (clean table)
        User.objects.all().delete()
        Questionnaire.objects.all().delete()
        Question.objects.all().delete()
        Answer.objects.all().delete()
        Game.objects.all().delete()
        Guess.objects.all().delete()
        print("clean Database")

    def user(self):
        " Insert users"
        print("Users")
        
        for i in range(N_USERS):
            faker = Faker()
            pf = faker.simple_profile()
            name = str(pf['name']).split(' ')

            user = {"username": pf['username'] + str(i),
                    "password": str(name[1] + str( pf['birthdate'])),
                    "first_name": name[0],
                    "last_name": name[1],
                    "email": pf['mail']}
            
            userdb = User(username=user['username'], 
                       first_name=user['first_name'], 
                       last_name=user['last_name'], 
                       password=user['password'],
                       email=user['email'])
            
            self.users.append(userdb)
            userdb.save()
            


    def questionnaire(self):
        "insert questionnaires"
        print("questionnaire")

        # assign users randomly to the questionnaires
        
        for i in range(N_QUENARI):
            faker = Faker()

            qnriedb = Questionnaire(title=faker.country(),
                                    user=self.users[random.randint(
                0, int(N_USERS-1))])
            
            self.questionnaires.append(qnriedb)

            qnriedb.save()
        


    def question(self):
        " insert questions, assign randomly to questionnaires"
        print("Question")
        faker = Faker()
        
        for i in range(N_QUES):
           
            qsdb = Question(question=faker.text(),
                                    questionnaire=self.questionnaires[random.randint(
                0, int(N_QUENARI-1))],
                answerTime= random.randint(5, 30))
            
            self.questions.append(qsdb)

            qsdb.save()

    def answer(self):
        "insert answers, one of them must be the correct one"
        print("Answer")
        faker = Faker()
        
        for i in range(N_ASW):

            boolean = False

            if not getrandbits(1):
                boolean = True
           
            qsdb = Answer(answer= faker.text(),
                          question=self.questions[random.randint(
                0, int(N_QUES-1))], correct= boolean)
            
            self.questions.append(qsdb)

            qsdb.save()

    def game(self):
        "insert some games"
        print("Game")
        faker = Faker()
        
        for i in range(N_GAMES):
            
            gdb = Game(questionnaire=self.questionnaires[
                random.randint(0, int(N_QUENARI-1))], 
                state=random.randint(1, 4), 
                countdownTime=random.randint(3, 20),
                questionNo=random.randint(1,10))
            
            

            gdb.save()
