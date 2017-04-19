#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/12 15:16:02 by ohesheli          #+#    #+#              #
#    Updated: 2016/12/12 15:16:05 by ohesheli         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = main.c check.c coords.c file_read.c ft.c help_functions.c solve.c

OBJ = $(SRC:.c=.o)

HEADER = fillit.h

all: $(NAME)

$(NAME): $(OBJ) 
	gcc -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	gcc -Wall -Werror -Wextra -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
