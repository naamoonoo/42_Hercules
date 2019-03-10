#include "hydra.h"

int ft_client(int sockfd, int PORT)
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
	servaddr.sin_addr.s_addr = inet_addr("172.20.10.2"); 
	servaddr.sin_port = htons(PORT); 
	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0)
	{
		printf("connection with the server failed...\n"); 
		exit(0); 
	}
	else
		printf("connected to the server..\n"); 

	while(1)
	{
		bzero(buff, sizeof(buff)); 
		printf("Enter the string : "); 
		n = 0; 
		while ((buff[n++] = getchar()) != '\n') 
			; 
		write(sockfd, buff, sizeof(buff)); 
		bzero(buff, sizeof(buff)); 
		read(sockfd, buff, sizeof(buff)); 
		printf("From Server : %s", buff); 
		if ((strncmp(buff, "exit", 4)) == 0) 
		{
			printf("Client Exit...\n"); 
			break; 
		} 
	} 

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
