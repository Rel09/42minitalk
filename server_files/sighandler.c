/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:39:30 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/15 00:54:57 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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

