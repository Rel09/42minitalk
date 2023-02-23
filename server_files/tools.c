/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:13:59 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/22 23:37:48 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	add_char_to_str() {
	get_headstr(ADD_CHAR, binary_to_char(get_bin()->str));
	get_bin()->i = 0;

	// End of Received String
	if (binary_to_char(get_bin()->str) == 0)
	{
		get_headstr(PRINT_ALL, 0);
		get_headstr(FREE_ALL, 0);
	}
}

char binary_to_char(const char *arr)
{
    int		i;
    char	result;
	
	i = 0;
	result = 0;
	while (i < 8)
        result = result * 2 + (arr[i++] - '0');
    return result;
}

