#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

int main()
{
	char * hello = "hello from client";
	struct sockaddr_in servaddr = {0};
	
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd == -1)
	{
		perror("failed to create socket");
		exit(EXIT_FAILURE);
	}
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(12345);
	servaddr.sin_addr.s_addr = INADDR_ANY;
	
	int len = sendto(sockfd, (const char *)hello, strlen(hello),
		0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
	if(len ==-1)
	{
		perror("failed to send");
	}
	close(sockfd);
	
    return 0;
}
