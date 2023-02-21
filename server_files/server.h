/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:10 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/21 01:27:31 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define INIT_ZERO 0
# define INIT_ONE 1

# define INIT_NEXT 0
# define NONE 1
# define GET_CURRENT 2

# include <stdio.h>	// 										Printf
# include <signal.h>// 										Signals
# include <unistd.h>// 										getpid / usleep
# include <stdlib.h>// 										uint8_t

typedef struct _str {
	char str[100];
	struct _str *next;
}	t_str;//												Struct that hold the Sent String

typedef struct _binary {
	uint8_t i;
	char str[8];
}	t_binary;//												Struct that hold the Binary Str

t_str 				*get_str(uint8_t mode);// 				Hold the Received Str		
t_binary			*get_bin();// 							Hold the Struct to Binary -> Str
char 				binary_to_char(const char *arr);//		Convert Binary to Char
struct sigaction	*get_structs(uint8_t mode);// 			Init Signals structs
uint8_t 			errormsg(uint8_t err_no);//				Basic Error Message
void				ft_writestr(char *s);//					Print Text, Printf cant handle this

#endif
