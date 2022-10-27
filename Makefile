# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 22:45:34 by sel-biyy          #+#    #+#              #
#    Updated: 2022/10/27 04:02:48 by sel-biyy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Wextra -Werror
CFILES= ft_printf.c ft_printf_functions.c
OBJ = $(CFILES:.c=.o)
NAME = libftprintf.a
LIBC = ar -rc
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	${LIBC} ${NAME} ${OBJ}

${OBJ}: ${CFILES}
	$(CC) $(CFLAGS) -I ./ -c ${CFILES}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all