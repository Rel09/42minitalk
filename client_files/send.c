/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:31:25 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/10 11:53:59 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void char_to_binary(char c)
{
    int	i;
	
	i = 0;
	for (int j = 7; j >= 0; --j)
    {
        if (c & (1 << j))
			data()->binary_str[i++] = '1';
		else
			data()->binary_str[i++] = '0';
	}
	data()->binary_str[i] = '\0';
}