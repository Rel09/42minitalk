/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:19 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 20:10:11 by dpotvin          ###   ########.fr       */
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
	printf("Server Process ID: [%i]\n", getpid());
	
	
	while (1)
	{ 
		signal(SIGUSR1, sig_one);
		signal(SIGUSR2, sig_two);
	}
	return 0;
}
