/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:30:32 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/24 23:37:44 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(char *s)
{
	uint8_t	i;
	int		num;

	i = 0;
	num = 0;
	while (s[i] && ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32)))
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num);
}

void	ft_itoa(int i, char *buffer)
{
	char	temp[16];
	char	*index;

	(void)buffer;
	index = &temp[15];
	temp[15] = '\0';
	while (i > 9)
	{
		*--index = (i % 10) + '0';
		i = i / 10;
	}
	*--index = (i % 10) + '0';
	add_code("#ID#", index);
	ft_copystr(buffer, index - ft_strlen("#ID#"));
}

void	char_to_binary(char c)
{
	int8_t	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(get_data()->server_id, SIGUSR2);
		else
			kill(get_data()->server_id, SIGUSR1);
		usleep(30);
		--i;
	}
}

t_bool	is_numeric(char *s)
{
	u_int8_t	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}
