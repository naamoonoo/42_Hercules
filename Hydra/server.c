#include "hydra.h"

int ft_server(char *PORT)
{
	int 					connected_fd;
	int 					n;
	int						sockfd;
	unsigned int			addr_size;
	char					buff[MAX];
	struct sockaddr_storage tehir_addr;
	struct addrinfo			adr;
	struct addrinfo			*res;

	bzero(&adr, sizeof(adr));
	adr.ai_family = AF_INET;
	adr.ai_socktype = SOCK_STREAM;
	adr.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, PORT, &adr, &res);

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

	if ((bind(sockfd, res->ai_addr, res->ai_addrlen)) != 0) 
	{
		printf("socket bind failed...\n");
		exit(0);
	} 
	else
		printf("Socket successfully binded..\n");

	if ((listen(sockfd, 5)) != 0) 
	{ 
		printf("Listen failed...\n");
		exit(0);
	} 
	else
		printf("[PORT : %s]Server listening..\n", PORT);

	addr_size = sizeof(tehir_addr);
	connected_fd = accept(sockfd, (SA*)&tehir_addr, &addr_size);
	if (connected_fd < 0) 
	{ 
		printf("server acccept failed...\n");
		exit(0);
	} 
	else
		printf("server acccept the client...\n");

	while (1)
	{ 
		bzero(buff, MAX);
		recv(connected_fd, buff, sizeof(buff), 0);
		if (strncmp("exit", buff, 4) == 0)
		{
			printf("Client has left the server...\n");
			printf("For new client, restart the server...\n");
			close(connected_fd);
			close(sockfd);
			return (1);
		}
		else
		{
			printf("[client] : %s[server] : ", buff);
			bzero(buff, MAX);
			n = 0;
			while ((buff[n++] = getchar()) != '\n') 
				;
			send(connected_fd, buff, sizeof(buff), 0);
			if (strncmp("exit", buff, 4) == 0)
			{
				printf("You close the server...\n");
				break;
			}	
		}	
	} 
	close(sockfd);
	return (0);
}
