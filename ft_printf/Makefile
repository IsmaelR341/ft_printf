# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ireal-po <ireal-po@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 20:45:36 by ireal-po          #+#    #+#              #
#    Updated: 2023/02/14 17:24:10 by ireal-po         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAG = -Wall -Werror -Wextra

SRC = ft_letters.c ft_printf.c

CC = gcc

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAG) -c $(SRC)
		ar rc $(NAME) $(OBJ)

re : fclean all

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

.PHONY : clean fclean all re