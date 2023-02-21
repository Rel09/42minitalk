/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:30:32 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/21 02:10:51 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(char *s)
{
	int	i;
	int num;

	i = 0;
	num = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32)))
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9') {
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return num;
}

void char_to_binary(char c)
{
	for (int j = 7; j >= 0; --j)
    {
        if (c & (1 << j))
			kill(get_data()->server_id, SIGUSR2);
		else
			kill(get_data()->server_id, SIGUSR1);
		usleep(250);
	}
}
