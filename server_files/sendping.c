/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 06:01:56 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/24 23:34:57 by dpotvin          ###   ########.fr       */
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

t_data	*get_pid(void)
{
	static t_data	t;

	return (&t);
}

void	print_all(t_str *T)
{
	while (T)
	{
		printf("%s", T->str);
		T = T->next;
	}
	printf("\n");
}

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
