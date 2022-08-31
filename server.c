/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:46:04 by romvan-d          #+#    #+#             */
/*   Updated: 2022/08/29 16:39:30 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_handler(int signum)
{
	static char	vault[8] = {0};
	static int	i = 0;

	if (signum == SIGUSR1)
		vault[i] = '0';
	else if (signum == SIGUSR2)
		vault[i] = '1';
	i++;
	if (i == CHAR_BIT)
	{
		ft_putchar_fd(binary_to_char(vault), 1);
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
