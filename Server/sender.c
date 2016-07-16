/* Sender of the file */
#include <stdlib.h>
#include <stdio.h>
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
	
	int sockfd, newfd, size, i=0, numbytes;
	char msg[max], buf[max], ch;
	struct sockaddr_in myaddr, theiraddr;
	pid_t cpid;
	FILE *fp;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(atoi(argv[2]));
	myaddr.sin_addr.s_addr = inet_addr(argv[1]);

	memset(&(myaddr.sin_zero),'\0',8);
	bind(sockfd,(struct sockaddr *) &myaddr, sizeof(struct sockaddr));

	listen(sockfd,10);
	for(;;){
		size = sizeof(struct sockaddr_in);
		while((newfd = accept(sockfd,(struct sockaddr*) &theiraddr, &size))<=0);
		cpid=fork();
		if(cpid==0){
			memset(buf,'\0',8);
			numbytes = recv(newfd,buf,max-1,0);
			buf[numbytes] = '\0';
			
			printf("Request from %s ",inet_ntoa(theiraddr.sin_addr));
			printf("for file:: %s ... ",buf);
			fp = fopen(buf,"r");
			if(fp==NULL){
				printf("Unable to locate file %s\n",buf);
				send(newfd,"bad_req",strlen("bad_req"),0);
			}
			else{

				while((ch=fgetc(fp))!=EOF)
					msg[i++] = ch;

				send(newfd,msg,strlen(msg),0);
				printf("File %s sent\n",buf);
				fclose(fp);
			}
		}
	}
	close(sockfd);
	return 0;
}
