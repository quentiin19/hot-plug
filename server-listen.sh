sudo tshark -i ens3 -f "host 37.166.199.222 and icmp" -T fields -e data -w capture.pcap >> /dev/null