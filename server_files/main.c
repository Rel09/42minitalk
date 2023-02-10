/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:19 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/10 12:46:45 by dpotvin          ###   ########.fr       */
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

void	sig_one(int num)
{
	recv()->data[recv()->i++] = '1';
	
	if (recv()->i == 8)
	{
		recv()->data[9] = '\0';
		recv()->i = 0;
		// Send PONG so client can continue
		// Call the convert function
	}
}

void	sig_two(int num)
{
	recv()->data[recv()->i++] = '0';
		if (recv()->i == 8)
	{
		recv()->data[9] = '\0';
		recv()->i = 0;
		// Send PONG so client can continue
		// Call the convert function
	}
}

int main (void)
{
	printf("Server Process ID: [%i]\n", getpid());
	
	while (1)
	{ 
		signal(SIGUSR1, sig_one);
		signal(SIGUSR2, sig_two);
	}
	return 0;
}
