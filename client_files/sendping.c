/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:32:17 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/24 23:51:12 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	add_code(const char *txt, char *buffer)
{
	int8_t	i;

	i = ft_strlen(txt) - 1;
	while (i >= 0)
		*--buffer = txt[i--];
}

void	zero_function(int a)
{
	(void)a;
	get_data()->waiting = 0;
	printf("[+] Server Received Message with Success !\n");
}

struct sigaction	*get_structs(void)
{
	static struct sigaction	zero;

	zero.__sigaction_u.__sa_handler = zero_function;
	sigemptyset(&zero.sa_mask);
	zero.sa_flags = 0;
	sigaction(SIGUSR1, &zero, 0);
	if (sigaction(SIGUSR1, &zero, 0) == -1)
		return (0);
	get_data()->waiting = 1;
	return (&zero);
}

void	send_data(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		char_to_binary(s[i++]);
	char_to_binary('\0');
}
