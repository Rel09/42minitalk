/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 06:01:56 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/23 06:42:14 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_bool	ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

t_data	*get_pid()
{
	static t_data t;

	return (&t);
}
