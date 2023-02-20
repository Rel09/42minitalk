/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:42 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/20 01:47:41 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H


# include <stdio.h>									// Prints
# include <signal.h>								// Signals
 #include <unistd.h>								// usleep
 
typedef struct _data {
	int server_id;
}	t_data;

void				char_to_binary(char c);			// Char to Binary
int					ft_atoi(char *s);				// Str to Int
 t_data 			*get_data();					// Hold Data


#endif
