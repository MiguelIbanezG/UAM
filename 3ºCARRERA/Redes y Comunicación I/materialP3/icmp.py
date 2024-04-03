'''
    icmp.py
    
    Funciones necesarias para implementar el nivel ICMP
    Autor: Javier Ramos <javier.ramos@uam.es>
    2022 EPS-UAM
'''
from ip import *
from threading import Lock
import struct
import time
import logging
from ip import registerIPProtocol, chksum, sendIPDatagram

ICMP_PROTO = 1


ICMP_ECHO_REQUEST_TYPE = 8
ICMP_ECHO_REPLY_TYPE = 0

timeLock = Lock()
icmp_send_times = {}

def process_ICMP_message(us,header,data,srcIp):
    '''
        Nombre: process_ICMP_message
        Descripción: Esta función procesa un mensaje ICMP. Esta función se ejecutará por cada datagrama IP que contenga
        un 1 en el campo protocolo de IP
        Esta función debe realizar, al menos, las siguientes tareas:
            -Calcular el checksum de ICMP:
                -Si es distinto de 0 el checksum es incorrecto y se deja de procesar el mensaje
            -Extraer campos tipo y código de la cabecera ICMP
            -Loggear (con logging.debug) el valor de tipo y código
            -Si el tipo es ICMP_ECHO_REQUEST_TYPE:
                -Generar un mensaje de tipo ICMP_ECHO_REPLY como respuesta. Este mensaje debe contener
                los datos recibidos en el ECHO_REQUEST. Es decir, "rebotamos" los datos que nos llegan.
                -Enviar el mensaje usando la función sendICMPMessage
            -Si el tipo es ICMP_ECHO_REPLY_TYPE:
                -Extraer del diccionario icmp_send_times el valor de tiempo de envío usando como clave los campos srcIP e icmp_id e icmp_seqnum
                contenidos en el mensaje ICMP. Restar el tiempo de envio extraído con el tiempo de recepción (contenido en la estructura pcap_pkthdr)
                -Se debe proteger el acceso al diccionario de tiempos usando la variable timeLock
                -Mostrar por pantalla la resta. Este valor será una estimación del RTT
            -Si es otro tipo:
                -No hacer nada

        Argumentos:
            -us: son los datos de usuarios pasados por pcap_loop (en nuestro caso este valor será siempre None)
            -header: estructura pcap_pkthdr que contiene los campos len, caplen y ts.
            -data: array de bytes con el conenido del mensaje ICMP
            -srcIP: dirección IP que ha enviado el datagrama actual.
        Retorno: Ninguno
    '''
    # Calcular el checksum de ICMP y comprobar si es correcto
    if chksum(data) != 0:
        logging.debug("Error el checksum es distinto de 0")
        return

    # Extraer campos tipo y código de la cabecera ICMP
    tipo = data[0]
    codigo = data[1]
    data_sincb = data[8:]
    
    # Loggear (con logging.debug) el valor de tipo y código
    logging.debug("Tipo: "+ str(tipo))
    logging.debug("Codigo: " + str(codigo))

    # Si el tipo es ICMP_ECHO_REQUEST_TYPE:
    # Generar un mensaje de tipo ICMP_ECHO_REPLY como respuesta. Este mensaje debe contener
    # los datos recibidos en el ECHO_REQUEST. Es decir, "rebotamos" los datos que nos llegan.
    if tipo == ICMP_ECHO_REQUEST_TYPE:
        # Enviar el mensaje usando la función sendICMPMessage
        sendICMPMessage(data_sincb,ICMP_ECHO_REPLY_TYPE,0,int.from_bytes(data[4:6], byteorder='big'),int.from_bytes(data[6:8], byteorder='big'),struct.unpack('!I',srcIp)[0])

    # Si el tipo es ICMP_ECHO_REPLY_TYPE:
    elif tipo == ICMP_ECHO_REPLY_TYPE:
    # Se debe proteger el acceso al diccionario de tiempos usando la variable timeLock:
        with timeLock:
            # Extraer del diccionario icmp_send_times el valor de tiempo de envío usando como clave los campos srcIP e icmp_id e icmp_seqnum # contenidos en el mensaje ICMP
            tiempo1 = icmp_send_times[int.from_bytes(srcIp, byteorder='big')+int.from_bytes(data[4:6], byteorder='big')+int.from_bytes(data[6:8], byteorder='big')]
        # Restar el tiempo de envio extraído con el tiempo de recepción (contenido en la estructura pcap_pkthdr)
        tiempo =  header.ts.tv_sec - tiempo1
        # Mostrar por pantalla la resta. Este valor será una estimación del RTT
        print("La estimación del RTT es: "+ str(tiempo))

def sendICMPMessage(data,type,code,icmp_id,icmp_seqnum,dstIP):
    '''
        Nombre: sendICMPMessage
        Descripción: Esta función construye un mensaje ICMP y lo envía.
        Esta función debe realizar, al menos, las siguientes tareas:
            -Si el campo type es ICMP_ECHO_REQUEST_TYPE o ICMP_ECHO_REPLY_TYPE:
                -Construir la cabecera ICMP
                -Añadir los datos al mensaje ICMP
                -Calcular el checksum y añadirlo al mensaje donde corresponda
                -Si type es ICMP_ECHO_REQUEST_TYPE
                    -Guardar el tiempo de envío (llamando a time.time()) en el diccionario icmp_send_times
                    usando como clave el valor de dstIp+icmp_id+icmp_seqnum
                    -Se debe proteger al acceso al diccionario usando la variable timeLock

                -Llamar a sendIPDatagram para enviar el mensaje ICMP
                
            -Si no:
                -Tipo no soportado. Se devuelve False

        Argumentos:
            -data: array de bytes con los datos a incluir como payload en el mensaje ICMP
            -type: valor del campo tipo de ICMP
            -code: valor del campo code de ICMP 
            -icmp_id: entero que contiene el valor del campo ID de ICMP a enviar
            -icmp_seqnum: entero que contiene el valor del campo Seqnum de ICMP a enviar
            -dstIP: entero de 32 bits con la IP destino del mensaje ICMP
        Retorno: True o False en función de si se ha enviado el mensaje correctamente o no
    '''

    icmp_message = bytes()

    # Si el campo type es ICMP_ECHO_REQUEST_TYPE o ICMP_ECHO_REPLY_TYPE
    if type == ICMP_ECHO_REQUEST_TYPE or type == ICMP_ECHO_REPLY_TYPE:
        
        # Construir la cabecera ICMP
        icmp_message += type.to_bytes(1, byteorder='big')
        icmp_message += code.to_bytes(1, byteorder='big') 
        header = bytes()
        header += icmp_id.to_bytes(2, byteorder='big')
        header +=icmp_seqnum.to_bytes(2, byteorder='big')

       # Calcular el checksum y añadirlo al mensaje donde corresponda
        checkSum = chksum(icmp_message + header + data).to_bytes(2, byteorder='little')

        # Añadir los datos al mensaje ICMP
        icmp_message += checkSum + header + data

        # Si type es ICMP_ECHO_REQUEST_TYPE
        if type == ICMP_ECHO_REQUEST_TYPE:

            # Se debe proteger al acceso al diccionario usando la variable timeLock
            with timeLock:
                # Guardar el tiempo de envío (llamando a time.time()) en el diccionario icmp_send_times
                icmp_send_times[dstIP+icmp_id+icmp_seqnum] = time.time()

        # Llamar a sendIPDatagram para enviar el mensaje ICM
        sendIPDatagram(dstIP, icmp_message, 1)
        
    else:
        return False

    

def initICMP():
    '''
        Nombre: initICMP
        Descripción: Esta función inicializa el nivel ICMP
        Esta función debe realizar, al menos, las siguientes tareas:
            -Registrar (llamando a registerIPProtocol) la función process_ICMP_message con el valor de protocolo 1

        Argumentos:
            -Ninguno
        Retorno: Ninguno
          
    '''
    registerIPProtocol(process_ICMP_message, 1)