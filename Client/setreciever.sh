gcc -o recv  reciever.c
echo -n "Connecting IP:"
read ip
echo -n "Port number:"
read port
./recv $ip $port


