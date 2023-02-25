/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:42 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/24 23:49:15 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum _bool
{
	false,
	true
}		t_bool;

typedef struct _data
{
	int		server_id;
	uint8_t	waiting;
}		t_data;

t_data				*get_data(void);
int					ft_atoi(char *s);
struct sigaction	*get_structs(void);
t_bool				is_numeric(char *s);
void				char_to_binary(char c);
int					errormsg(uint8_t mode);
void				send_data(const char *s);
int					ft_strlen(const char *s);
void				ft_itoa(int i, char *buffer);
void				ft_copystr(char *str, char *tocopy);
void				add_code(const char *txt, char *buffer);

#endif
