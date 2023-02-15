/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:39:30 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 21:51:20 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	next_char()
{
	recv()->data[9] = '\0';
	// Reset index to 0 for the new Binary array
	recv()->i = 0;
		
	// Add char to String
	data()->str[data()->i++] = binaryToChar(recv()->data);

	// Check if this is a command
	command(data()->str[data()->i - 1]);
}

void	listen_zero() {
	recv()->data[recv()->i++] = '0';
	size()->count++;
	
	// If we have received the 8 bytes of this one char, add char to String
	if (recv()->i == 8)
		next_char();
}

void	listen_one()
{
	recv()->data[recv()->i++] = '1';
	size()->count++;
	// If we have received the 8 bytes of this one char, add char to String
	if (recv()->i == 8)
		next_char();
}

void	recv_zero()
{
	
}

void	recv_one()
{
	
}
