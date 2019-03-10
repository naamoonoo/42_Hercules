#include "hydra.h"

int	main(int ac, char *av[])
{
	int PORT;
	int sockfd;

	if (ac != 3)
	{
		printf("./hydra server/client PortNumber\n[example] ./hydra server 8800\n");
		return (1);
	}
	if(!(PORT = atoi(av[2])))
	{
		printf("put the valid port number\n");
		return (1);
	}
	else
	{
		sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	}
	if (strcmp(av[1], "server") == 0)
		ft_server(sockfd, PORT);
	else if (strcmp(av[1], "client") == 0)
		ft_client(sockfd, PORT);
	else
	{
		printf("choose between server and client\n");
		return (1);
	}
	return (0);
}