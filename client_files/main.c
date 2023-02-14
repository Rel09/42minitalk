/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:38 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/12 22:36:22 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"


void	connect_client(const char *str, int sleep)
{
	for (int i = 0; str[i]; i++) {
		char_to_binary(str[i]);
		//printf("%c = %s\n", data()->input_str[i], data()->binary_str);

		for (int j = 0; data()->binary_str[j]; j++) {

			if (data()->binary_str[j] == '0') 
				kill(data()->process_id, SIGUSR1);
			else
				kill(data()->process_id, SIGUSR2);
			
			//printf("Sending: %c\n", data()->binary_str[j]);
			usleep(sleep);
		}
	}
	// Send String Terminaison
	
}

int main (int argv, char **argc)
{
	if (!parser(argv, argc))
		return (0);
		
	// Send Client PID to Server so we can Ping Pong every actions - Safety
	connect_client("CPID:", 500);
	connect_client(&data()->clientpid[data()->pidi], 500);
	connect_client("\\0", 500);
	printf("Sending %i\n", getpid());





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
