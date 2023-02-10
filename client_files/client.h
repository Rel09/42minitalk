/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:42 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/10 11:53:21 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <stdio.h>				
# include <unistd.h>
# include <signal.h>

# define WAIT 0
# define RUN 1

// Alternative to stdbool					- Bool
typedef enum _bool {
	false,
	true
}	t_bool;

// Struct for get_data						- Hold PID
typedef struct _pid {
	int		process_id;
	char	*input_str;
	t_bool 	mode;
	int		binary_index;
	char	binary_str[9];
}	t_pid;

// Primary Functions
t_pid	*data(void);//					- Fake Global, Hold Data
t_bool	parser(int argv, char **argc);//	- Input Parser
void	char_to_binary(char c);//			- Convert Char to Binary

// Tools
t_bool	is_numeric(char *s);
int		ft_atoi(char *s);

#endif
