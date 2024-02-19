import sys
from scapy.all import *
import time
import os

if len(sys.argv) != 2:
        print("Usage: python3 script.py <chemin_du_fichier>")
        sys.exit(1)

file_path = sys.argv[1]

pcap_file = rdpcap(file_path)


host_ip = 'fa:16:3e:31:10:49'


flag_file_name = False
flag_file_data = False
changed = False

file_name = "./datadump"


ip_packet = {}

for pack in pcap_file:
    if IP in pack and ICMP in pack and str(pack.src) != host_ip:
        # Ajoutez l'adresse IP source à la liste
        data_encrypted = pack[ICMP].payload
        
        data = data_encrypted.load[16:]

        if "<<<file>>>".encode() in data:
              # créer le fichier avec le bon nom
              flag_file_name = True
              flag_file_data = False
              # mettre en variable le nom fichier

        elif "<<<data>>>".encode() in data:
              # écrire dans le fichier
              flag_file_name = False
              flag_file_data = True

              print("file_name: ", file_name)

              os.makedirs(os.path.dirname(file_name), exist_ok=True)

        elif "<<<fin>>>".encode() in data:
              # fermer le fichier
              flag_file_name = False
              flag_file_data = False

              file_name = "./datadump"
              
        else:
                if flag_file_name:
                        if '#'.encode() in data:
                                file_name += (data.decode().split('#')[0])
                        else:
                                file_name += (data.decode()[0:16])

                elif flag_file_data:
                        try:
                                with open(str(file_name), "ab") as file:
                                        if '#'.encode() in data:
                                                file.write(data.split('#'.encode())[0])
                                        else:
                                                file.write(data[0:16])
                        except:
                                with open(str(file_name), "wb") as file:
                                        if '#'.encode() in data:
                                                file.write(data.split('#'.encode())[0])
                                        else:
                                                file.write(data[0:16])
                

