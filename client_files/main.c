/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:38 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 21:49:32 by dpotvin          ###   ########.fr       */
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

	if (data()->mode == CONNECTED)
	{
		printf("Connected Successfully - Sending Data\n");



		
	}
	else
		printf("Connection Failed - No response from Server\n");
	

	// Send Raw String
	/*
	for (int i = 0; data()->input_str[i]; i++) {
		char_to_binary(data()->input_str[i]);
		printf("%c = %s\n", data()->input_str[i], data()->binary_str);

		for (int j = 0; data()->binary_str[j]; j++) {

			if (data()->binary_str[j] == '0') 
				kill(data()->process_id, SIGUSR1);
			else
				kill(data()->process_id, SIGUSR2);
			
			printf("Sending: %c\n", data()->binary_str[j]);
			usleep(1);	
			// Add Pong Here
		}
	}
	*/
	return 0;
}
