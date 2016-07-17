gcc -o serv sender.c

echo -n "Connecting IP:"
read ip
echo -n "Port number:"
read port
echo "Server Running"

./serv $ip $port

