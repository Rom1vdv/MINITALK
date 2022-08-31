/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:46:04 by romvan-d          #+#    #+#             */
/*   Updated: 2022/08/31 14:43:49 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	my_handler(int signum)
{
	static	char	vault[8] = {0};
	static	int	i = 0;
	static	char buffer[BUFFER_SIZE] = {0};
	static	int	char_count = 0;

	if (signum == SIGUSR1)
		vault[i] = '0';
	else if (signum == SIGUSR2)
		vault[i] = '1';
	i++;
	if (i == CHAR_BIT)
	{
		buffer[char_count] = binary_to_char(vault);
		if (buffer[char_count] == '\0' || char_count == BUFFER_SIZE - 2)
			{
				printf("%s\n", buffer);
				char_count = 0;
				memset(buffer, 0, BUFFER_SIZE);
			}
		else
			char_count++;
		memset(vault, 0, CHAR_BIT);
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
