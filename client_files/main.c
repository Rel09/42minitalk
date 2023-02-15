/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:38 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 20:30:57 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"


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
	// Send String Terminaison
}

int main (int argv, char **argc)
{
	if (!parser(argv, argc))
		return (0);
		
	// Attempt to connect to server
	connect_client(&data()->clientpid[data()->pidi], 500);

	// Wait for Ping
	








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
