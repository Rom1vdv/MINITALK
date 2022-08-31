/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:27:11 by romvan-d          #+#    #+#             */
/*   Updated: 2022/08/31 14:43:48 by romvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H 

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

# define BUFFER_SIZE 1000000

void	ft_putnbr_fd(long int n, int fd);
void	*my_malloc(size_t size);
char	*char_to_binary(unsigned char character);
char	binary_to_char(char *binary);
void	ft_putchar_fd(char c, int fd);
void	ft_error(char *str);

#endif