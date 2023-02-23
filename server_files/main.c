/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:19 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/22 23:35:13 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_binary	*get_bin()
{
	static t_binary T;
	return (&T);
}

t_str	*get_headstr(uint8_t mode, char c)
{
	static t_str		*T;
	static uint8_t		size;
	t_str*				temp;

	if (!T)
	{
		T = malloc(sizeof(t_str));
		if (!T) {
			printf("ERROR - Problem with malloc\n");
			exit(1);
		}
		T->next = 0;
	}

	if (mode == ADD_CHAR)
	{
		// Get to the last NODE that we are
		temp = T;
		while (temp->next)
			temp = temp->next;
			
		// Input the char
		temp->str[size++] = c;

		// Go to the next node if this one is filled
		if (size == 99)
		{
			temp->next = malloc(sizeof(t_str));
			temp = temp->next;
			temp->next = 0;
			size = 0;
		}
	}

	else if (mode == FREE_ALL)
	{
		while (T)
		{
			temp = T->next;
			free(T);
			T = temp;
		}
		T = 0;
		size = 0;
	}

	else if (mode == PRINT_ALL)
	{
		while (T)
		{
			printf("%s", T->str);
			T = T->next;
		}
		printf("\n");
		
	}
	

	
	return (T);
}

int main (void)
{
	printf("[Server PID: %i]\n", getpid());
	if (!get_structs(INIT_ZERO) || !get_structs(INIT_ONE))
		return (errormsg(1));
		
	while (1) 
		usleep(1);
		
	return 0;
}
