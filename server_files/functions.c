/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:49:23 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/23 03:59:56 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	zero_function(int x)
{
	(void)x;
	get_bin()->str[get_bin()->i++] = '0';
	if (get_bin()->i == 8)
		add_char_to_str();
}

static void	one_function(int x)
{
	(void)x;
	get_bin()->str[get_bin()->i++] = '1';
	if (get_bin()->i == 8)
		add_char_to_str();
}

struct sigaction	*get_structs(uint8_t mode)
{
	static struct sigaction	zero;
	static struct sigaction	one;

	if (mode == INIT_ZERO)
	{
		zero.__sigaction_u.__sa_handler = zero_function;
		sigemptyset(&zero.sa_mask);
		zero.sa_flags = 0;
		sigaction(SIGUSR1, &zero, 0);
		if (sigaction(SIGUSR1, &zero, 0) == -1)
			return (0);
		return (&zero);
	}
	else if (mode == INIT_ONE)
	{
		one.__sigaction_u.__sa_handler = one_function;
		sigemptyset(&one.sa_mask);
		one.sa_flags = 0;
		sigaction(SIGUSR2, &one, 0);
		if (sigaction(SIGUSR2, &one, 0) == -1)
			return (0);
		return (&one);
	}
	return (0);
}
