#include "hydra.h"

int ft_server(int sockfd, int PORT)
{
	int connfd;
	unsigned int len;
	int n; 
	int cli;
	char buff[MAX]; 
	
	struct sockaddr_in servaddr;

	bzero(&servaddr, sizeof(servaddr)); 
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 

	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) 
	{
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n"); 

	if ((listen(sockfd, 5)) != 0) { 
		printf("Listen failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server listening..\n"); 
	len = sizeof(cli); 

	connfd = accept(sockfd, (SA*)&cli, &len); 
	if (connfd < 0) { 
		printf("server acccept failed...\n"); 
		exit(0); 
	} 
	else
		printf("server acccept the client...\n"); 

	// infinite loop for chat 
	while(1)
	{ 
		bzero(buff, MAX); 
		// read the message from client and copy it in buffer 
		read(connfd, buff, sizeof(buff)); 
		// print buffer which contains the client contents 
		printf("From client: %s\nTo client : ", buff); 
		bzero(buff, MAX); 
		n = 0; 
		// copy server message in the buffer 
		while ((buff[n++] = getchar()) != '\n') 
			;
  
		// and send that buffer to client 
		write(connfd, buff, sizeof(buff)); 
  
		// if msg contains "Exit" then server exit and chat ended. 
		if (strncmp("exit", buff, 4) == 0)
		{
			printf("Server Exit...\n"); 
			break; 
		}
	} 

	close(sockfd); 
	return (0);
}
