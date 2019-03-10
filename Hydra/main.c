#include "hydra.h"

int	main(int ac, char *av[])
{
	int sockfd;

	if (ac != 3)
	{
		printf("./hydra server/client PortNumber\n[example] ./hydra server 8800\n");
		return (1);
	}
	if(!av[2])
	{
		printf("put the valid port number\n");
		return (1);
	}
	if (strcmp(av[1], "server") == 0)
	{
		if(ft_server(av[2]) == 1)
			ft_server(av[2]);
	}
	else if (strcmp(av[1], "client") == 0)
		ft_client(av[2]);
	else
	{
		printf("choose between server and client\n");
		return (1);
	}
	return (0);
}