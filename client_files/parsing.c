/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:51:29 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 20:59:42 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_bool	is_numeric(char *s)
{
	int	i;

	i = 0;
	while (s[i]) {
		if (!(s[i] >= '0' && s[i] <= '9'))
			return false;
		i++;
	}
	return true;
}

int	ft_atoi(char *s)
{
	int	i;
	int num;

	i = 0;
	num = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		num = num * 10 + (s[i++] - '0');
	return (num);
}

t_bool parser(int argv, char **argc)
{
	if (argv != 3 || !is_numeric(argc[1]))
		return false;
	data()->process_id = ft_atoi(argc[1]);
	data()->input_str = argc[2];
	savepid(getpid());
	return true;
}
