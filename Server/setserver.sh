make>/dev/null
touch /dev/null

echo -n "Connecting IP:"
read ip
echo -n "Port number:"
read port
echo "Server Running"
./send $ip $port

