/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:38 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/24 23:57:15 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	errormsg(uint8_t mode)
{
	if (mode == 1)
		printf("Invalid Input\n");
	return (1);
}

t_data	*get_data(void)
{
	static t_data	t;

	return (&t);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_copystr(char *str, char *tocopy)
{
	int8_t	i;

	i = -1;
	while (++i < ft_strlen(tocopy))
		str[i] = tocopy[i];
}

int	main(int argv, char **argc)
{
	int		count;
	char	buffer[16];

	if (argv != 3 || !is_numeric(argc[1]))
		return (errormsg(1));
	get_data()->server_id = ft_atoi(argc[1]);
	ft_itoa(getpid(), buffer);
	send_data(buffer);
	send_data(argc[2]);
	if (!get_structs())
	{
		printf("Problem with Sigaction\n");
		return (0);
	}
	count = 0;
	while (get_data()->waiting)
	{
		usleep(1);
		count++;
		if (count > 500000){
			printf("No response from Server\n");
			break;
		}
	}
	return (0);
}
// Bunch of emojis to test
/*
👋🌎🌞🌻🍔🎉🎓💰🎁🎄🎃🐶🐱🦁🐵🐻🦊🐯🐮🐷🦄🐙🐬🐠🦐🍕🍩🍺🍸🍹🚀🚲🚁🚗🚊🏰🗽💻📱🎧🎬🎨🏀
⚽️🎲🎮🎤🎹🎸🚣‍♀️🚴‍♀️🏊‍♂️🏋️‍♂️🚶‍♂️🏃‍♀️🎭🎬🎥🎫🎟️🎭🎯🎳🎰🎳🎿🎾🎱🎲🎮🃏🀄️🎴🎭🎫🎟️🎙️🎚️🎛️🕰️🕯️🛍️💄👠👒👑
👓👜👛🧢🧣👔👕👖🧥👗👘👙👚👞👟🥾🥿👡🩰🥼🦺🧤🧦🧥👙🧢🎓🎩🧢🎓🎒👝💼👜👛🎁🎀🎊🎉🎈🎂🍰🧁
🍭🍬🍫🍩🍪🍕🍔🍟🌭🌮🌯🍲🍛🍜🍝🍠🥔🥕🥦🍆🍅🥒🌶️🥑🥬🥝🍓🍇🍉🍊🍌🍍🥭🥥🥜🌰🍯🍞🧀🥐🥖🥨🥯
🍳🍔🍕🍟🍗🥩🥓🍖🌭🍞🥪🥙🥚🥞🧇🥓🍟🥤🍹🍺🍷🍾🥂🍸🥃🍻🥛🍼🥤🧃🧉🥢🍽️🍴🥄🏺🎁🎂🎊🎉🎈🎆🎇
🎃🎄🎅🎁🎍🎑🎏🎉🎈🎁🎂🎊🎃🎄🎇🎆🎁🎉🎋🎎🎏🎐🎑🎌🏮
*/
