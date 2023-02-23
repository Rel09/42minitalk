/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:10 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/22 23:38:09 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define INIT_ZERO 0
# define INIT_ONE 1

# define ADD_CHAR 0
# define PRINT_ALL 1
# define FREE_ALL 2

# include <stdio.h>	// 										Printf
# include <signal.h>// 										Signals
# include <unistd.h>// 										getpid / usleep
# include <stdlib.h>// 										uint8_t

typedef struct _str {
	char str[100];
	struct _str *next;
}	t_str;//												Linked list

typedef struct _binary {
	uint8_t i;
	char str[8];
}	t_binary;//												Binary -> Str Conversion

t_binary			*get_bin();// 							Hold the Struct to Binary -> Str
void				add_char_to_str();//					Add Character to String
uint8_t 			errormsg(uint8_t err_no);//				Basic Error Message
struct sigaction	*get_structs(uint8_t mode);// 			Init Signals structs
char 				binary_to_char(const char *arr);//		Convert Binary to Char
t_str				*get_headstr(uint8_t mode, char c);//	Get the head of Str Linked List

#endif
