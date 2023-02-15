/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:42 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 21:01:12 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdio.h>				
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define UNCONNECTED 0
# define CONNECTED 1

// Alternative to stdbool					- Bool
typedef enum _bool {
	false,
	true
}	t_bool;

// Struct for data				- Hold PID
typedef struct _pid {
	t_bool 	mode;// 			- Sending Mode
	
	int 	pidi;//				- Index of Process PID
	char 	clientpid[12];//	- This Process PID
	
	int		process_id;//		- Entered PID
	char	*input_str;//		- Entered STRING

	int		binary_index;//		- Index of Binary Array
	char	binary_str[9];//	- Binary Array
}	t_pid;




// Secondary Functions
void	connect_client(const char *str, int sleep);//	- Send PID to Server
void	await_connect();//								- Wait PING from Server

// Primary Functions
t_pid	*data(void);//						- Fake Global, Hold Data
t_bool	parser(int argv, char **argc);//	- Input Parser
void	char_to_binary(char c);//			- Convert Char to Binary

// Tools
t_bool	is_numeric(char *s);//				- Check if String is Numeric
int		ft_atoi(char *s);//					- Convert String to Int
void	savepid(int num);//			- Convert PID to String

#endif
