/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:37:23 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/12 22:37:51 by dpotvin          ###   ########.fr       */
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
