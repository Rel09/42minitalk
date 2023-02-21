/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:48:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:52 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

uint8_t errormsg(uint8_t err_no)
{
	if (err_no == 1)
		printf("Error Initializing Signals\n");
	return (1);
}
