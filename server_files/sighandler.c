/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:39:30 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/12 23:25:38 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sig_two()
{
	recv()->data[recv()->i++] = '1';
	size()->count++;
	if (recv()->i == 8)
	{
		recv()->data[9] = '\0';
		recv()->i = 0;
		// Add char to String
		data()->str[data()->i++] = binaryToChar(recv()->data);

		// Check if this is a Special Event
		if (size()->count >= 1 && data()->str[data()->i - 1] == '0' && data()->str[data()->i - 1 - 2] == '\\')
		{
			// Print & Free all Linked List except the first one. reset index and thats it
			data()->str[data()->i - 2] = '\0';
			data()->i = 0;
			printf("[%s]\n", data()->str);
		}
		// Send PONG so client can continue

	}
}

void	sig_one()
{
	recv()->data[recv()->i++] = '0';
	size()->count++;
	if (recv()->i == 8)
	{
		recv()->data[9] = '\0';
		recv()->i = 0;
		// Add char to String
		data()->str[data()->i++] = binaryToChar(recv()->data);
		if (size()->count >= 1 && data()->str[data()->i - 1] == '0' && data()->str[data()->i - 2] == '\\')
		{
			// Print & Free all Linked List except the first one. reset index and thats it
			data()->str[data()->i - 2] = '\0';
			data()->i = 0;
			printf("[%s]\n", data()->str);
		}
		
		// Send PONG so client can continue

	}
}
