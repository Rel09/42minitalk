/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:10 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/10 12:43:25 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <stdio.h>
# include <unistd.h>
# include <signal.h>

typedef struct _data {
	uint8_t	i;
	char	str[100];
	t_data	*next;
}	t_data;

typedef struct _recv {
	uint8_t i;
	char	data[9];
}	t_recv;

t_recv 	*recv(void);//			- Grab the Received Data
t_data	*data(void);//			- Hold Linked List
#endif
