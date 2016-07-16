# OverDracht
What is OverDratch?

  OverDratch is a server-client program with a server that serves request of text files to its multiple connected clients. Basically this project follows the single server multiple client model for transferring text files from server to other cleints, where multiple clients can be connected one after another as well as all at a time.
  
  The key feature of OverDratch is the single server multiple client model where once the server is set on any node of the network other nodes can access files located in the server directory by joining as a client. Multiple client all at a time and also one after another is feasible in this model.
  
Requirements :white_check_mark:
-------------------------------

:pushpin: gcc version 5.x

:pushpin: Any GNU/Linux operating system

:pushpin: CMake

Easy Compilation and Run:arrow_forward:
---------------------------------------
Once you have setup the dependencies, download the source and compile:
```
$ cd ~/Downloads
$ git clone https://github.com/Subarno/OverDracht.git
$ cd OverDracht
```
Setup and Run the Server
```
$ cd Server
$./setserver.sh
```
After the Server is set up multplie clients can be connected from different ends for different requests.

Setup and Run the client 
```
$ cd Client
$./setreciever.sh
```

> Happy To Code ... Happy To Live :octocat:
