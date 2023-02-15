/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:47:11 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/15 00:47:30 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	command(char c)
{
	uint8_t m;
	
	m = mode()->mode;
	// Try to connect to Client
	if (m == UNCONNECTED && c == '#')
		connect_to_client();

	else if (m == CONNECTED && c == '#')
	{
		printf("%s\n", data()->str);
		data()->i = 0;
	}
}

void	next_char()
{
	recv()->data[9] = '\0';
	// Reset index to 0 for the new Binary array
	recv()->i = 0;
		
	// Add char to String
	data()->str[data()->i++] = binaryToChar(recv()->data);

	// Check if this is a command
	command(data()->str[data()->i - 1]);
}

void	connect_to_client()
{
	uint8_t count;
	mode()->client_pid = ft_atoi(data()->str);
	data()->str[data()->i - 1] = '\0';
	data()->i = 0;
	
	printf("Connection Requested by Client: [%i]\n", mode()->client_pid);
	
	// Try to Etablish connection
	count = 0;
	while (count < 5) {
		usleep(2000);
		kill(mode()->client_pid, SIGUSR1);
		count++;
	}
	mode()->mode = CONNECTED;
}
