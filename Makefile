# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:23:44 by romvan-d          #+#    #+#              #
#    Updated: 2022/08/31 15:13:00 by romvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

CLIENT_SRCS = utils.c utils2.c client.c ft_atoi.c

SERVER_SRCS = utils.c utils2.c server.c ft_atoi.c

CLIENT_OBJS = ${CLIENT_SRCS:.c=.o}
SERVER_OBJS = ${SERVER_SRCS:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:    ${CLIENT} ${SERVER}

${CLIENT}:	${CLIENT_OBJS}
		${CC} ${CFLAGS} -o ${CLIENT} ${CLIENT_OBJS}

${SERVER}:	${SERVER_OBJS}
		${CC} ${CFLAGS} -o ${SERVER} ${SERVER_OBJS}
	


clean:
		${RM} ${SERVER_OBJS} ${CLIENT_OBJS}

fclean:         clean
		${RM} ${CLIENT} ${SERVER}

re: fclean all

.PHONY: all clean fclean re