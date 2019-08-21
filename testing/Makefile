# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 11:42:07 by jsarkis           #+#    #+#              #
#    Updated: 2019/08/21 11:05:36 by jsarkis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CHKR = checker
PSHSWP = push_swap
HEADER = ../includes/push_swap.h

CFLAGS = -Wall -Werror -Wextra
LINK = -L./libft -lft
SRCS =  validation.c \
	   

LIB = libft/libft.a

all: $(LIB) $(CHKR) $(HEADER) 

$(LIB):
	make -C libft

$(CHKR): checker.c $(SRCS) $(HEADER)
	gcc $(CFLAGS) checker.c $(SRCS) $(LINK) -o $(CHKR)

fclean:
	rm $(CHKR)
	make -C libft fclean

re: fclean all
