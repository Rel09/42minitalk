/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:13:59 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/23 06:44:41 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_writestr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	add_char_to_str(void)
{
	char this_char;
	
	this_char = binary_to_char(get_bin()->str);
	get_headstr(ADD_CHAR, this_char);
	get_bin()->i = 0;
	
	// If this is the Client ProcessID
	if (this_char == 0 && ft_strstr(get_headstr(RETURN_STR, 0)->str, "#ID#"))
	{
		printf("Received ID: [%s]\n", get_headstr(RETURN_STR, 0)->str);
		get_headstr(FREE_ALL, 0);
	}
	else if (this_char == 0)
	{
		get_headstr(PRINT_ALL, 0);
		get_headstr(FREE_ALL, 0);
	}
}

char	binary_to_char(const char *arr)
{
	int		i;
	char	result;

	i = 0;
	result = 0;
	while (i < 8)
		result = result * 2 + (arr[i++] - '0');
	return (result);
}

void	add_to_str(t_str *T, uint8_t *i, char c)
{
	t_str	*temp;

	temp = T;
	while (temp->next)
		temp = temp->next;
	temp->str[(*i)++] = c;
	if (*i == 99)
	{
		temp->next = malloc(sizeof(t_str));
		temp = temp->next;
		temp->next = 0;
		*i = 0;
	}
}

void	free_all(t_str **T, uint8_t *i)
{
	t_str	*temp;

	while (*T)
	{
		temp = (*T)->next;
		free(*T);
		*T = temp;
	}
	*T = 0;
	*i = 0;
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
