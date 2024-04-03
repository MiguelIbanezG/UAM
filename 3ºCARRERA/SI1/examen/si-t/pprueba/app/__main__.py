#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Para ejecutar sin Apache/mod_wsgi, en directorio con .wsgi:
# PYTHONPATH=. python3 -m app

from app import app

if __name__ == "__main__":
    app.run(host='192.168.58.253', port=5000, debug=True)

