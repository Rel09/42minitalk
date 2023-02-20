/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:19 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/20 04:55:26 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	add_char_to_str() {
	static t_str* T;
	static uint8_t index;

	if (!T)
		T = get_str(NONE);
	
	T->str[index++] = binary_to_char(get_bin()->str);
	get_bin()->i = 0;

	if (index == 99)
	{
		T->str[99] = '\0';
		T = get_str(INIT_NEXT);
		index = 0;
	}
}

char binary_to_char(const char *arr)
{
    int i;
    char result;
	t_str* temp;
	t_str* old;
	
	result = 0;
    for (i = 0; i < 8; i++) {
        result = result * 2 + (arr[i] - '0');
    }
	
	// End of Received String
	// Bug is happening here ser
	if (result == 0)
	{
		printf("Doing stuff\n");

		temp = get_str(NONE);
		while (temp) {
			printf("%s", temp->str);
			temp = temp->next;
		}
		
	}
    return result;
}



void zero_function() {
	get_bin()->str[get_bin()->i++] = '0';
	if (get_bin()->i == 8)
		add_char_to_str();
}

void one_function() {
	get_bin()->str[get_bin()->i++] = '1';
	if (get_bin()->i == 8)
		add_char_to_str();
}

struct sigaction *get_structs(uint8_t mode)
{
	static struct sigaction zero;
	static struct sigaction one;
	
	if (mode == INIT_ZERO)
	{
		zero.__sigaction_u.__sa_handler = zero_function;
		sigemptyset(&zero.sa_mask);
		zero.sa_flags = 0;
		sigaction(SIGUSR1, &zero, 0);
		if (sigaction(SIGUSR1, &zero, NULL) == -1)
			return 0;
		return (&zero);
	}
	else if (mode == INIT_ONE)
	{
		one.__sigaction_u.__sa_handler = one_function;
		sigemptyset(&one.sa_mask);
		one.sa_flags = 0;
		sigaction(SIGUSR2, &one, 0);
		if (sigaction(SIGUSR2, &one, NULL) == -1)
			return 0;
		return (&one);
	}
	return (0);
}

t_binary	*get_bin() {
	static t_binary T;
	return (&T);
}

t_str		*get_str(uint8_t mode) {
	static t_str *head;
	static t_str *current;
	
	if (!head)
		head = malloc(sizeof(t_str*));

	if (mode == INIT_NEXT) {
		if (!current) {
			printf("\nFirst Malloc\n");
			head->next = malloc(sizeof(t_str*));
			current = head->next;
		}
		else {
			printf("\nNext\n");
			current->next = malloc(sizeof(t_str*));
			current = current->next;
		}
		return (current);
	}
		
	return (head);
}

int main (void)
{
	printf("Server PID: %i\n", getpid());
	
	if (!get_structs(INIT_ZERO) || !get_structs(INIT_ONE))
	{
		printf("Error Initializing Signals\n");
		return (1);
	}
	while (1) {
		usleep(1);
	}
	return 0;
}
