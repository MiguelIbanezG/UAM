'''
    ip.py
    
    Funciones necesarias para implementar el nivel IP
    Autor: Javier Ramos <javier.ramos@uam.es>
    2022 EPS-UAM
'''
from ethernet import *
from arp import *
from fcntl import ioctl
from math import ceil, floor
import subprocess
import socket
import struct
import logging


SIOCGIFMTU = 0x8921
SIOCGIFNETMASK = 0x891b
#Diccionario de protocolos. Las claves con los valores numéricos de protocolos de nivel superior a IP

#por ejemplo (1, 6 o 17) y los valores son los nombres de las funciones de callback a ejecutar.
protocols={}
#Tamaño mínimo de la cabecera IP
IP_MIN_HLEN = 20
#Tamaño máximo de la cabecera IP
IP_MAX_HLEN = 60
def chksum(msg):
    '''
        Nombre: chksum
        Descripción: Esta función calcula el checksum IP sobre unos datos de entrada dados (msg)
        Argumentos:
            -msg: array de bytes con el contenido sobre el que se calculará el checksum
        Retorno: Entero de 16 bits con el resultado del checksum en ORDEN DE RED
    '''
    s = 0
    y = 0x07E6       
    for i in range(0, len(msg), 2):
        if (i+1) < len(msg):
            a = msg[i] 
            b = msg[i+1]
            s = s + (a+(b << 8))
        elif (i+1)==len(msg):
            s += msg[i]
        else:
            raise 'Error calculando el checksum'
    y = y & 0x00ff
    s = s + (s >> 16)
    s = ~s & 0xffff

    return s

def getMTU(interface):
    '''
        Nombre: getMTU
        Descripción: Esta función obteiene la MTU para un interfaz dada
        Argumentos:
            -interface: cadena con el nombre la interfaz sobre la que consultar la MTU
        Retorno: Entero con el valor de la MTU para la interfaz especificada
    '''
    s = socket.socket(socket.AF_PACKET, socket.SOCK_RAW)
    ifr = struct.pack('16sH', interface.encode("utf-8"), 0)
    mtu = struct.unpack('16sH', ioctl(s,SIOCGIFMTU, ifr))[1]
   
    s.close()
   
    return mtu
   
def getNetmask(interface):
    '''
        Nombre: getNetmask
        Descripción: Esta función obteiene la máscara de red asignada a una interfaz 
        Argumentos:
            -interface: cadena con el nombre la interfaz sobre la que consultar la máscara
        Retorno: Entero de 32 bits con el valor de la máscara de red
    '''
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    ip = fcntl.ioctl(
        s.fileno(),
       SIOCGIFNETMASK,
        struct.pack('256s', (interface[:15].encode('utf-8')))
    )[20:24]
    s.close()
    return struct.unpack('!I',ip)[0]


def getDefaultGW(interface):
    '''
        Nombre: getDefaultGW
        Descripción: Esta función obteiene el gateway por defecto para una interfaz dada
        Argumentos:
            -interface: cadena con el nombre la interfaz sobre la que consultar el gateway
        Retorno: Entero de 32 bits con la IP del gateway
    '''
    p = subprocess.Popen(['ip r | grep default | awk \'{print $3}\''], stdout=subprocess.PIPE, shell=True)
    dfw = p.stdout.read().decode('utf-8')
    print(dfw)
    return struct.unpack('!I',socket.inet_aton(dfw))[0]



def process_IP_datagram(us,header,data,srcMac):
    '''
        Nombre: process_IP_datagram
        Descripción: Esta función procesa datagramas IP recibidos.
            Se ejecuta una vez por cada trama Ethernet recibida con Ethertype 0x0800
            Esta función debe realizar, al menos, las siguientes tareas:
                -Extraer los campos de la cabecera IP (includa la longitud de la cabecera)
                -Calcular el checksum y comprobar que es correcto                    
                -Analizar los bits de de MF y el offset. Si el offset tiene un valor != 0 dejar de procesar el datagrama (no vamos a reensamblar)
                -Loggear (usando logging.debug) el valor de los siguientes campos:
                    -Longitud de la cabecera IP
                    -IPID
                    -TTL
                    -Valor de las banderas DF y MF
                    -Valor de offset
                    -IP origen y destino
                    -Protocolo
                -Comprobar si tenemos registrada una función de callback de nivel superior consultando el diccionario protocols y usando como
                clave el valor del campo protocolo del datagrama IP.
                    -En caso de que haya una función de nivel superior registrada, debe llamarse a dicha funciñón 
                    pasando los datos (payload) contenidos en el datagrama IP.
        
        Argumentos:
            -us: Datos de usuario pasados desde la llamada de pcap_loop. En nuestro caso será None
            -header: cabecera pcap_pktheader
            -data: array de bytes con el contenido del datagrama IP
            -srcMac: MAC origen de la trama Ethernet que se ha recibido
        Retorno: Ninguno
    '''

    
    ihl = "{:08b}".format(int(data[0:1].hex(),16))[4:]
    ihl=int(ihl, 2)
    
    IPID = data[4:6]

    # Calcular el checksum y comprobar que es correcto  
    # Comprobar que el resultado del checksum es 0. Si es distinto el datagrama se deja de procesar
    if chksum(data[:10] + data[12:ihl*4]).to_bytes(2, byteorder='little') != data[10:12]:
        return
    

    # Extraer los campos de la cabecera IP
    fg = "{:08b}".format(int(data[6:7].hex(),16))[:3]
    offset = "{:08b}".format(int(data[6:8].hex(),16))[3:]
    protocolo = data[9:10]
    checksum = data[10:12]
    ip_origen = data[12:16]
    ip_destino = data[16:20]
    ttl = data[8:9]
    payload = data[ihl*4:]
 
    # Si el offset tiene un valor != 0 dejar de procesar el datagrama (no vamos a reensamblar)
    offset=int(offset, 2)
    if offset != 0:
        return

    # Loggear (usando logging.debug) el valor de los siguientes campos:
    logging.debug("Cabecera IP: " + str(ihl*4))
    logging.debug('IPID: ' + str(IPID.hex()))
    logging.debug("TTL: "+str(ttl))
    logging.debug("DF flag: "+ fg[1])
    logging.debug("MF flag: "+ fg[2])
    logging.debug("offset: "+str(offset))
    logging.debug("IP Origen: "+str(ip_origen))
    logging.debug("IP Destino: "+str(ip_destino))
    logging.debug('Protocolo: ' + str(protocolo.hex()))


    # Comprobar si tenemos registrada una función de callback de nivel superior consultando el diccionario protocols y usando como clave el valor del campo protocolo del datagrama IP.
    # En caso de que haya una función de nivel superior registrada, debe llamarse a dicha función
    protocolo = int.from_bytes(protocolo, byteorder='big')
    if protocolo in protocols.keys():
        protocols[protocolo](us, header, payload, ip_origen)


def registerIPProtocol(callback,protocol):
    '''
        Nombre: registerIPProtocol
        Descripción: Esta función recibirá el nombre de una función y su valor de protocolo IP asociado y añadirá en la tabla 
            (diccionario) de protocolos de nivel superior dicha asociación. 
            Este mecanismo nos permite saber a qué función de nivel superior debemos llamar al recibir un datagrama IP  con un 
            determinado valor del campo protocolo (por ejemplo TCP o UDP).
            Por ejemplo, podemos registrar una función llamada process_UDP_datagram asociada al valor de protocolo 17 y otra 
            llamada process_ICMP_message asocaida al valor de protocolo 1. 
        Argumentos:
            -callback_fun: función de callback a ejecutar cuando se reciba el protocolo especificado. 
                La función que se pase como argumento debe tener el siguiente prototipo: funcion(us,header,data,srcIp):
                Dónde:
                    -us: son los datos de usuarios pasados por pcap_loop (en nuestro caso este valor será siempre None)
                    -header: estructura pcap_pkthdr que contiene los campos len, caplen y ts.
                    -data: payload del datagrama IP. Es decir, la cabecera IP NUNCA se pasa hacia arriba.
                    -srcIP: dirección IP que ha enviado el datagrama actual.
                La función no retornará nada. Si un datagrama se quiere descartar basta con hacer un return sin valor y dejará de procesarse.
            -protocol: valor del campo protocolo de IP para el cuál se quiere registrar una función de callback.
        Retorno: Ninguno 
    '''
    protocols[protocol] = callback

def initIP(interface,opts=None):
    global myIP, MTU, netmask, defaultGW,ipOpts, IPID
    '''
        Nombre: initIP
        Descripción: Esta función inicializará el nivel IP. Esta función debe realizar, al menos, las siguientes tareas:
            -Llamar a initARP para inicializar el nivel ARP
            -Obtener (llamando a las funciones correspondientes) y almacenar en variables globales los siguientes datos:
                -IP propia
                -MTU
                -Máscara de red (netmask)
                -Gateway por defecto
            -Almacenar el valor de opts en la variable global ipOpts
            -Registrar a nivel Ethernet (llamando a registerCallback) la función process_IP_datagram con el Ethertype 0x0800
            -Inicializar el valor de IPID con el número de pareja
        Argumentos:
            -interface: cadena de texto con el nombre de la interfaz sobre la que inicializar ip
            -opts: array de bytes con las opciones a nivel IP a incluir en los datagramas o None si no hay opciones a añadir
        Retorno: True o False en función de si se ha inicializado el nivel o no
    '''
    # Llamar a initARP para inicializar el nivel ARP
    initARP(interface)

    # Obtener (llamando a las funciones correspondientes) y almacenar en variables globales los siguientes datos:
    myIP = getIP(interface)
    MTU = getMTU(interface)
    netmask = getNetmask(interface)
    defaultGW = getDefaultGW(interface)
    # Almacenar el valor de opts en la variable global ipOpts
    ipOpts = opts

    # Registrar a nivel Ethernet (llamando a registerCallback) la función process_IP_datagram con el Ethertype 0x0800
    registerCallback(process_IP_datagram,0x0800)

    # Inicializar el valor de IPID con el número de pareja 
    IPID = 6

    return True

def sendIPDatagram(dstIP,data,protocol):
    global IPID,MTU, ipOpts, defaultGW, defaultMac
    '''
        Nombre: sendIPDatagram
        Descripción: Esta función construye un datagrama IP y lo envía. En caso de que los datos a enviar sean muy grandes la función
        debe generar y enviar el número de fragmentos IP que sean necesarios.
        Esta función debe realizar, al menos, las siguientes tareas:
            -Determinar si se debe fragmentar o no y calcular el número de fragmentos
            -Para cada datagrama o fragmento:
                -Construir la cabecera IP con los valores que corresponda.Incluir opciones en caso de que ipOpts sea distinto de None
                -Calcular el checksum sobre la cabecera y añadirlo a la cabecera
                -Añadir los datos a la cabecera IP
                -En el caso de que sea un fragmento ajustar los valores de los campos MF y offset de manera adecuada
                -Enviar el datagrama o fragmento llamando a sendEthernetFrame. Para determinar la dirección MAC de destino
                al enviar los datagramas se debe hacer unso de la máscara de red:                  
            -Para cada datagrama (no fragmento):
                -Incrementar la variable IPID en 1.
        Argumentos:
            -dstIP: entero de 32 bits con la IP destino del datagrama 
            -data: array de bytes con los datos a incluir como payload en el datagrama
            -protocol: valor numérico del campo IP protocolo que indica el protocolo de nivel superior de los datos
            contenidos en el payload. Por ejemplo 1, 6 o 17.
        Retorno: True o False en función de si se ha enviado el datagrama correctamente o no
          
    '''

    IHL = 5 
    # Se ha utilizado bytearray 
    ip_header = bytes()
    taman= len(data)
    
    if(ipOpts is not None):
        opt=len(ipOpts)/4
        if(opt<=10):
            IHL += opt 
    taman_real = MTU-(IHL*4)

    # Para determinar la dirección MAC de destino al enviar los datagramas se debe hacer unso de la máscara de red
    mac = ARPResolution(dstIP) 

    # Utilizamos la funcion floor para comprobar que el el tamaño maximo de datos es divisible entre 8
    taman_real = floor(taman_real/8)*8
    cabecera = bytearray()

    # Construir la cabecera IP con los valores que corresponda.
    cabecera += int((4<<4) + IHL).to_bytes(1, byteorder='big')
    cabecera += int(0).to_bytes(1, byteorder='big')
    cabecera += int(taman_real+IHL*4).to_bytes(2, byteorder='big')
    # En este caso todos los fragmentos tienen el mismo valor de IPID
    cabecera += int(IPID).to_bytes(2, byteorder='big')
    cabecera += int((1 << 13)).to_bytes(2, byteorder='big')
    cabecera += int(64).to_bytes(1, byteorder='big')
    cabecera += protocol.to_bytes(1, byteorder='big')
   
    cabecera_2p = bytearray()
    cabecera_2p += myIP.to_bytes(4, byteorder='big')
    cabecera_2p += dstIP.to_bytes(4, byteorder='big')

    # Incluir opciones en caso de que ipOpts sea distinto de None
    if(ipOpts is not None):
        cabecera_2p += ipOpts

    # Para el numero de fragmentos de entero usamos la funcion CEIL que número hacia arriba hasta el próximo número entero
    fragmentos = ceil(taman / taman_real)
 
    # Para cada datagrama o fragmento:
    for i in range(fragmentos - 1):
        offset = taman_real*i
        cabecera[6:8] = int((1 << 13) + (offset/8)).to_bytes(2, byteorder='big')
        data_restante = data[offset:offset+taman_real]
        #Calcular el checksum sobre la cabecera y añadirlo a la cabecera
        checkSum = chksum(cabecera+cabecera_2p).to_bytes(2, byteorder='little')
        frame = cabecera + checkSum + cabecera_2p + data_restante
    
        #Enviar el datagrama o fragmento llamando a sendEthernetFrame
        sendEthernetFrame(frame, len(frame), 0x0800, mac)
    
    offset=taman_real*(fragmentos-1)

    cabecera[2:4] = int((taman_real-(taman_real)*(fragmentos-1))+IHL*4).to_bytes(2, byteorder='big')
    cabecera[6:8] = int((offset/8)).to_bytes(2, byteorder='big')

    checkSum = chksum(cabecera+cabecera_2p).to_bytes(2, byteorder='little')

    data_restante = data[offset:offset+taman_real]

    frame = cabecera + checkSum + cabecera_2p + data_restante
    sendEthernetFrame(frame, len(frame), 0x0800, mac)

    #Incrementar la variable IPID en 1
    IPID+=1
