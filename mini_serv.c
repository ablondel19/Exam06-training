/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:49:05 by ablondel          #+#    #+#             */
/*   Updated: 2022/10/15 19:11:23 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

void	error(char *err)
{
	write(2, "Fatal error\n", 12);
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
		error("Wrong number of arguments\n");
	
	//setup_server();
	//run_server();
	
}