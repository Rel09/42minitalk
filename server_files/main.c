/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:19 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/23 04:26:33 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_binary	*get_bin(void)
{
	static t_binary	t;

	return (&t);
}

t_str	*get_headstr(uint8_t mode, char c)
{
	static t_str	*t;
	static uint8_t	size;

	if (!t)
	{
		t = malloc(sizeof(t_str));
		if (!t)
		{
			printf("ERROR - Problem with malloc\n");
			exit(1);
		}
		t->next = 0;
	}
	if (mode == ADD_CHAR)
		add_to_str(t, &size, c);
	else if (mode == FREE_ALL)
		free_all(&t, &size);
	else if (mode == PRINT_ALL)
		print_all(t);
	return (t);
}

uint8_t	errormsg(uint8_t err_no)
{
	if (err_no == 1)
		printf("Error Initializing Signals\n");
	return (1);
}

int	main(void)
{
	printf("[Server PID: %i]\n", getpid());
	if (!get_structs(INIT_ZERO) || !get_structs(INIT_ONE))
		return (errormsg(1));
	while (1)
		usleep(1);
	return (0);
}
