#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from app import app
from flask import render_template, request, url_for, redirect, session
import json
import os
import sys

@app.route('/',methods=['GET', 'POST'])
@app.route('/base', methods=['GET', 'POST'])
def index():
    print (url_for('static', filename='css/si1.css'), file=sys.stderr)

    return render_template('base.html', title = "Home")


@app.route('/calc', methods=['GET', 'POST'])
def calc():

    x = int(request.args.get('valor1'))
    y = int(request.args.get('valor2'))
    return "Resultado: " + str(x + y)
