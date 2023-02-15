/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:19 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/15 00:55:03 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_data	*data(void)
{
	static t_data T;
	return (&T);
}

t_recv	*recv(void)
{
	static t_recv T;
	return (&T);
}

t_size	*size(void)
{
	static t_size T;
	return (&T);
}

t_signal *mode(void)
{
	static t_signal T;
	return (&T);
}

int main (void)
{
	while (1)
	{
		printf("Server Listening: [%i]\n", getpid());
		
		// Wait for a connection
		while (mode()->mode == UNCONNECTED)
		{ 
			signal(SIGUSR1, listen_zero);
			signal(SIGUSR2, listen_one);
		}

		// Reset String
		recv()->i = 0;
		data()->i = 0;

		// If we're Connected / Waiting for data response
		while (mode()->mode == CONNECTED || mode()->mode == WAITING)
		{
			signal(SIGUSR1, listen_zero);
			signal(SIGUSR2, listen_one);
		}
		
	}
	// Receive Data until we dont receive any anymore, then go back to Unconnected
	
	return 0;
}
