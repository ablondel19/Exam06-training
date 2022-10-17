/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:49:05 by ablondel          #+#    #+#             */
/*   Updated: 2022/10/17 15:21:20 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

void	error(int where)
{
	write(2, "Fatal error\n", 12);
	printf("{%d}\n", where);
	exit(1);
}

//void	setup_s_addr()
	//assign IP, PORT 
	//servaddr.sin_family = AF_INET; 
	//servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	//servaddr.sin_port = htons(atoi(av[1])); 

//void	setup_and_listen()
	//socket(); || error
	//setup_s_addr();
	//bind(); || error();
	//listen(); || error();
	
//void	get_message()
	//recv()

//void	notify_all()
	//send();

//void	disconnect()
	//close();

//void	run_server()
	//while (1)
		//select fd from the fd_set
		//accept client until max fd
		//get_message(from current client);
		//notify_all(other clients with current client message);
		//disconnect(close current client);

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	//SERVER////////////////////////////////////////////////////////////////////////////
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;
	fd_set read_set, write_set, client_set;

	// socket creation and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
		error(0);
	
	// assign IP, PORT 
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		error(1);
	
	//Listenning on sockfd and verification
	if (listen(sockfd, 10) != 0)
		error(2);

	//CLIENT////////////////////////////////////////////////////////////////////////////
	len = sizeof(cli);
	connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
	if (connfd < 0)
		error(3);
    else
        printf("server acccept the client %d...\n", connfd);
	char buffer[4096];
	size_t bytes_read = recv(connfd, buffer, 4096, NULL);
	printf("[%s]\n", buffer);
	size_t bytes_written = send(1, buffer, 4096, NULL);
	return 0;
}