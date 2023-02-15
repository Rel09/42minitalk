/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:47:11 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 21:50:57 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	command(char c)
{
	// Try to connect to Client
	if (mode()->client_pid == UNCONNECTED && c == '#')
		connect_to_client();
}

void	connect_to_client()
{
	uint8_t count;
	
	data()->str[data()->i - 1] = '\0';
	data()->i = 0;
	printf("Connection Requested by Client: [%s]\n", data()->str);
	
	// Try to Etablish connection
	count = 0;
	while (count < 5) {
		usleep(2000);
		kill(ft_atoi(data()->str), SIGUSR1);
		count++;
	}
	mode()->mode = CONNECTED;
}
