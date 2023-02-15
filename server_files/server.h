/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:10 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 20:22:07 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
//# include <inttypes.h>	// Ubuntu

# define UNCONNECTED 0
# define CONNECTED 1
# define RECEIVING_DATA 2

typedef struct _count {
	int	count;
}	t_size;

typedef struct _data {
	int				i;
	char			str[100];
	struct _data	*next;
}	t_data;

typedef struct _recv {
	uint8_t i;
	char	data[10];
}	t_recv;

typedef struct _signal {
	uint8_t mode;
	int		client_pid;
}	t_signal;

void		sig_one();//					- Hooked Signal 1
void		sig_two();//					- Hooked Signal 2

void		listen_zero();//				- Listening signal Zero
void		listen_one();//					- Listening signal One

t_size		*size(void);//					- Hold the Current size
t_recv 		*recv(void);//					- Grab the Received Data
t_data		*data(void);//					- Hold Linked List
t_signal 	*mode(void);//					- Hold the Connection

void		end_of_char();//				- When we have received the 8 Binary of the char

char binaryToChar(const char *arr);//		-Convert Binary to Char
#endif
