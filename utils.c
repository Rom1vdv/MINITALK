/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:25:46 by romvan-d          #+#    #+#             */
/*   Updated: 2022/08/31 14:43:49 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*char_to_binary(unsigned char character)
{
	int		i;
	char	*encoded_string;

	i = 0;
	encoded_string = my_malloc(CHAR_BIT + 1);
	while (i < 8)
	{
		encoded_string[i] = ((character >> (7 - i) & 1)) + 48;
		i++;
	}
	encoded_string[i] = '\0';
	return (encoded_string);
}

char	binary_to_char(char *binary)
{
	int		i;
	char	decoded_char;

	i = 0;
	decoded_char = 0;
	while (i < CHAR_BIT)
	{
		decoded_char += (binary[7 - i] - 48) << i;
		i++;
	}
	return (decoded_char);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(long int number, int fd)
{
	if (fd < 0)
	{
		write(2, "Wrong FD", 9);
		exit(EXIT_FAILURE);
	}
	if (number < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd(number % 10 + 48, fd);
}

void	*ft_memset(void *str, int c, size_t len)
{
	int				i;
	unsigned char	*ptr;

	ptr = (unsigned char *) str;
	i = 0;
	while (len > 0)
	{
		ptr[i] = c;
		i++;
		len --;
	}
	return (str);
}
