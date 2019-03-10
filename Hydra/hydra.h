#ifndef HYDRA_H
# define HYDRA_H

#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#include <netdb.h> 
#include <arpa/inet.h>

#define MAX 1000
#define SA struct sockaddr
// #define IP_ADDRESS 172.20.10.2

int ft_client(int sockfd, int PORT);
int ft_server(int sockfd, int PORT);

# endif