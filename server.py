import sys
from scapy.all import *
import time

if len(sys.argv) != 2:
        print("Usage: python3 script.py <chemin_du_fichier>")
        sys.exit(1)

file_path = sys.argv[1]

pcap_file = rdpcap(file_path)


host_ip = 'fa:16:3e:31:10:49'


flag_file_name = False
flag_file_data = False

file_name = ""


ip_packet = {}

for pack in pcap_file:
    if IP in pack and ICMP in pack and str(pack.src) != host_ip:
        # Ajoutez l'adresse IP source à la liste
        data_encrypted = pack[ICMP].payload
        
        data = data_encrypted.load[16:].decode()

        if "<<<file>>>" in data:
              # créer le fichier avec le bon nom
              flag_file_name = True
              flag_file_data = False
              # mettre en variable le nom fichier

        elif "<<<data>>>" in data:
              # écrire dans le fichier
              flag_file_name = False
              flag_file_data = True

        elif "<<<fin>>>" in data:
                # fermer le fichier
              flag_file_name = False
              flag_file_data = False
              
        else:
                if flag_file_name:
                        if '#' in data:
                                file_name += (data.split('#')[0])
                        else:
                                file_name += (data[0:16])

                elif flag_file_data:
                        try:
                                with open(str("./datadump.txt"), "a") as file:
                                        if '#' in data:
                                                file.write(data.split('#')[0])
                                        else:
                                                file.write(data[0:16])
                        except:
                                with open(str("./datadump.txt"), "w") as file:
                                        if '#' in data:
                                                file.write(data.split('#')[0])
                                        else:
                                                file.write(data[0:16])
                
