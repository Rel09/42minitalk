/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:39:30 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 20:25:25 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"



void	end_of_char()
{
	recv()->data[9] = '\0';
		// Reset index to 0
		recv()->i = 0;
		
		// Add char to String
		data()->str[data()->i++] = binaryToChar(recv()->data);

		// Check if this is a Special Event
		if (size()->count >= 1 && data()->str[data()->i - 1] == '#')
		{
			// Print & Free all Linked List except the first one. reset index and thats it
			data()->str[data()->i - 1] = '\0';
			data()->i = 0;
			printf("[%s]\n", data()->str);
		}
}


void	listen_zero() {
	recv()->data[recv()->i++] = '0';
	size()->count++;
	
	// If we have received the 8 bytes of this one char, add char to String
	if (recv()->i == 8)
		end_of_char();
}

void	listen_one()
{
	recv()->data[recv()->i++] = '1';
	size()->count++;
	// If we have received the 8 bytes of this one char, add char to String
	if (recv()->i == 8)
		end_of_char();
}



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
