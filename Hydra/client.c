#include "hydra.h"

int ft_client(char *PORT)
{
	int 				n;
	int					sockfd;
	char				buff[MAX];
	struct addrinfo		adr;
	struct addrinfo		*res;

	bzero(&adr, sizeof(adr));
	adr.ai_family = AF_INET;
	adr.ai_socktype = SOCK_STREAM;
	adr.ai_flags = AI_PASSIVE;
	getaddrinfo("10.112.7.25", PORT, &adr, &res);
	// addrress info ifconif | grep inet

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0)
	{
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("[PORT : %s]connected to the server..\n", PORT);

	while(1)
	{
		bzero(buff, sizeof(buff));
		printf("[client] : ");
		n = 0;
		while ((buff[n++] = getchar()) != '\n') 
			;
		send(sockfd, buff, sizeof(buff), 0);
		if (strncmp("exit", buff, 4) == 0)
		{
			printf("You left the server...\n");
			break;
		}
		bzero(buff, sizeof(buff));
		recv(sockfd, buff, sizeof(buff), 0);
		if (strncmp("exit", buff, 4) == 0)
		{
			printf("Server has be closed...\n");
			break;
		}
		printf("[server] : %s", buff);

	} 

	close(sockfd);
	return (0);}
