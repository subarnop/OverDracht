/* Reciever program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define max 100

int main( int argc, char** argv){

	if(argc<3){
		printf("Not enough arguments\n");
		exit(0);
	}

	int sockfd, numbytes, i=0;
	struct sockaddr_in their_addr;
	char buf1[max], msg1[max], ch;
	FILE* fr;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(atoi(argv[2]));
	their_addr.sin_addr.s_addr = inet_addr(argv[1]);

	memset(&(their_addr.sin_zero),'\0',8);
	connect(sockfd,(struct sockaddr*) &their_addr,sizeof(struct sockaddr));

	printf("Enter the file name ::");
	while((ch=getchar())!='\n'){
		msg1[i++] = ch;
	}
	msg1[i]='\0';
	send(sockfd,msg1,strlen(msg1),0);

	numbytes = recv(sockfd,buf1,max-1,0);
	if(strcmp(buf1,"bad_req")==0){
		printf("Bad request. File not found\n");
	}
	else{
		fr = fopen(msg1,"w");
		fputs(buf1,(FILE*)fr);
		printf("recieved:: %s\n",msg1);
		fclose(fr);
	}
	close(sockfd);

}
