/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:10 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/23 04:15:47 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define INIT_ZERO 0
# define INIT_ONE 1

# define ADD_CHAR 0
# define PRINT_ALL 1
# define FREE_ALL 2

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct _str {
	char		str[100];
	struct _str	*next;
}	t_str;

typedef struct _binary {
	uint8_t	i;
	char	str[8];
}	t_binary;

t_binary			*get_bin(void);
void				add_char_to_str(void);
void				print_all(t_str *T);
uint8_t				errormsg(uint8_t err_no);
struct sigaction	*get_structs(uint8_t mode);
void				free_all(t_str **T, uint8_t *i);
char				binary_to_char(const char *arr);
t_str				*get_headstr(uint8_t mode, char c);
void				add_to_str(t_str *T, uint8_t *i, char c);

#endif
