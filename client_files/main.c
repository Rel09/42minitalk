/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:38 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 22:32:27 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_pid	*data(void) {
	static t_pid T;
	return (&T);
}

void	connect_client(const char *str, int sleep)
{
	for (int i = 0; str[i]; i++) {
		char_to_binary(str[i]);

		for (int j = 0; data()->binary_str[j]; j++) {

			if (data()->binary_str[j] == '0') 
				kill(data()->process_id, SIGUSR1);
			else
				kill(data()->process_id, SIGUSR2);
			
			usleep(sleep);
		}
	}
}

void	await_connect()
{
	data()->mode = CONNECTED;
}

int main(int argv, char **argc)
{
	// Parse Input
	if (!parser(argv, argc))
		return (0);
		
	// Attempt to connect to server
	connect_client(&data()->clientpid[data()->pidi], 500);

	// Wait for Answer from server
	int tickcount;
	tickcount = 0;
	while (data()->mode == UNCONNECTED && tickcount < 300)
	{
		signal(SIGUSR1, await_connect);
		usleep(2000);
		tickcount++;
	}
	
	// If the mode is Connected OR waiting
	if (data()->mode == CONNECTED)
	{
		printf("Connected Successfully - Sending Data\n");

		for (int i = 0; data()->input_str[i]; i++) {
			char_to_binary(data()->input_str[i]);
		
			for (int j = 0; data()->binary_str[j]; j++) {
			
				usleep(20000);
				
				/*
				if (data()->binary_str[j] == '0') 
				{
					printf("sending 0\n");
					kill(data()->process_id, SIGUSR1);
				}
				else
				{
					printf("sending 1\n");
					kill(data()->process_id, SIGUSR2);
				}
				
				// Wait until we receive Ping back
				data()->mode = WAITING;
				while (data()->mode == WAITING)
					signal(SIGUSR1, await_connect);
				*/
			
			}
		}
		
	}
	else
		printf("Connection Failed - No response from Server\n");
	
	return 0;
}
