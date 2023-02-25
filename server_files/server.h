/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:10 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/24 23:34:37 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define INIT_ZERO 0
# define INIT_ONE 1

# define ADD_CHAR 0
# define PRINT_ALL 1
# define FREE_ALL 2
# define RETURN_STR 3

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef enum _bool {false, true}	t_bool;

typedef struct _str {
	char		str[100];
	struct _str	*next;
}	t_str;

typedef struct _binary {
	uint8_t	i;
	char	str[8];
}	t_binary;

typedef struct _data {
	int	clientpid;
}	t_data;

t_data				*get_pid(void);
t_binary			*get_bin(void);
int					ft_atoi(char *s);
void				print_all(t_str *T);
void				add_char_to_str(void);
uint8_t				errormsg(uint8_t err_no);
struct sigaction	*get_structs(uint8_t mode);
void				free_all(t_str **T, uint8_t *i);
char				binary_to_char(const char *arr);
t_str				*get_headstr(uint8_t mode, char c);
void				add_to_str(t_str *T, uint8_t *i, char c);
t_bool				ft_strstr(const char *str, const char *to_find);

#endif
