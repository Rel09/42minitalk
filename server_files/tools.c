/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:37:23 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 20:45:11 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char binaryToChar(const char *arr) {
    int i;
    char result;
	
	result = 0;
    for (i = 0; i < 8; i++) {
        result = result * 2 + (arr[i] - '0');
    }
    return result;
}

int	ft_atoi(char *s) {
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
