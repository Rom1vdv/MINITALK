/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:32:44 by romvan-d          #+#    #+#             */
/*   Updated: 2022/08/31 14:43:38 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>

void	ft_send_data(int pid, char *payload)
{
	int		j;
	char	*binary;

	j = 0;
	while (!j || payload[-1])
	{
		j = 0;
		binary = char_to_binary(*payload);
		while (j < CHAR_BIT)
		{
			if (binary[j] == '0')
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error("Kill failed, leaving process.");
			}
			else if (binary[j] == '1')
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error("Kill failed, leaving process.");
			}
			j++;
			usleep(50);
		}
		payload++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*payload;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		payload = argv[2];
		ft_send_data(pid, payload);
	}
	else
		ft_error("Wrong amount of arguments.");
	return (0);
}
