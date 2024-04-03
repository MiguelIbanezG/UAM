'''
    practica1.py
    Muestra el tiempo de llegada de los primeros 50 paquetes a la interfaz especificada
    como argumento y los vuelca a traza nueva con tiempo actual

    Autor: Javier Ramos <javier.ramos@uam.es>
    2020 EPS-UAM
	
	Giancarlo Lazo y Miguel Ibáñez González
'''

from rc1_pcap import *
import sys
import binascii
import signal
import argparse
from argparse import RawTextHelpFormatter
import time
import logging

ETH_FRAME_MAX = 1514
PROMISC = 1
NO_PROMISC = 0
TO_MS = 10
num_paquete = 0
TIME_OFFSET = 30*60

def signal_handler(nsignal,frame):
	logging.info('Control C pulsado')
	if handle:
		pcap_breakloop(handle)
		

def procesa_paquete(us,header,data):
	global num_paquete, pdumper
	logging.info('Nuevo paquete de {} bytes capturado en el timestamp UNIX {}.{}'.format(header.len,header.ts.tv_sec,header.ts.tv_sec))
	num_paquete += 1
	
	#Escribir el trafico al fichero de captura con el offset temporal
	header.ts.tv_sec += TIME_OFFSET
	header.ts = timeval(header.ts.tv_sec, header.ts.tv_usec)

	if pdumper is None:
		desc = pcap_open_dead(DLT_EN10MB, ETH_FRAME_MAX)

		if args.interface is not False:
			pdumper = pcap_dump_open(desc, 'captura'+str(args.interface)+str(time.time())+'.pcap')
		else:
			pdumper = pcap_dump_open(desc, 'captura.file'+args.tracefile+str(time.time())+'.pcap')

	
	#TODO imprimir los N primeros bytes
	list = str(binascii.hexlify(data[:args.nbytes])) 
	i=0
	while i < int(args.nbytes)+2: #Ponemos el +2 para que se ejecute el numero exacto de bytes que se pone como argumeto en la terminal					
		print(list[i], end = '')
		if i%2 !=0:
			print(' ', end = '')
		i+=1
	print("")

	#Escribir el trafico al fichero de captura con el offset temporal
	pcap_dump(pdumper, header, data)
		

	
if __name__ == "__main__":
	global pdumper,args,handle
	parser = argparse.ArgumentParser(description='Captura trafico de una interfaz ( o lee de fichero) y muestra la longitud y timestamp de los 50 primeros paquetes',
	formatter_class=RawTextHelpFormatter)
	parser.add_argument('--file', dest='tracefile', default=False,help='Fichero pcap a abrir')
	parser.add_argument('--itf', dest='interface', default=False,help='Interfaz a abrir')
	parser.add_argument('--nbytes', dest='nbytes', type=int, default=14,help='Numero de bytes a mostrar por paquete')
	parser.add_argument('--debug', dest='debug', default=False, action='store_true',help='Activar Debug messages')
	args = parser.parse_args()

	if args.debug:
		logging.basicConfig(level = logging.DEBUG, format = '[%(asctime)s %(levelname)s]\t%(message)s')
	else:
		logging.basicConfig(level = logging.INFO, format = '[%(asctime)s %(levelname)s]\t%(message)s')

	if args.tracefile is False and args.interface is False:
		logging.error('No se ha especificado interfaz ni fichero')
		parser.print_help()
		sys.exit(-1)

	signal.signal(signal.SIGINT, signal_handler)

	errbuf = bytearray()

	pdumper = None

	if args.interface is not False: #argumento itf
		#TODO abrir la interfaz especificada para captura o la traza
		handle =  pcap_open_live('ens33',ETH_FRAME_MAX,0,100,errbuf)
		if handle is None:
			print("none en pcap_open_live, usando argumento itf") 
			sys.exit(-1)
		

	elif args.tracefile is not False: #argumento file
		handle = pcap_open_offline(args.tracefile,errbuf)
		if handle is None:
			print("None en pcap_open_offline, usando argumento file")
			sys.exit(-1)
	
	
	ret = pcap_loop(handle,50,procesa_paquete,None)
	if ret == -1:
		logging.error('Error al capturar un paquete')
	elif ret == -2:
		logging.debug('pcap_breakloop() llamado')
	elif ret == 0:
		logging.debug('No mas paquetes o limite superado')
	logging.info('{} paquetes procesados'.format(num_paquete))
	
	#TODO si se ha creado un dumper cerrarlo
	if pdumper is not None:
		pcap_dump_close(pdumper)
	if handle is not None:
		pcap_close(handle)
