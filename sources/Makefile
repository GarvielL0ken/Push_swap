# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 11:42:07 by jsarkis           #+#    #+#              #
#    Updated: 2019/07/15 18:16:42 by jsarkis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CHKR = checker
PSHSWP = push_swap
HEADER = push_swap.h

CFLAGS = -Wall -Werror -Wextra
LINK = -L./libft -lft
SRCS = debug.c \
	   error_handling.c \
	   execution.c \
	   init_lists.c \
	   node_functions.c \
	   read_instructions.c \
	   validation.c

all: $(PSHSWP) $(CHKR) 

$(PSHSWP): push_swap.c $(SRCS)
	gcc $(CFLAGS) push_swap.c $(SRCS) $(LINK) -o $(PSHSWP)

$(CHKR): checker.c $(SRCS)
	gcc $(CFLAGS) checker.c $(SRCS) $(LINK) -o $(CHKR)

fclean:
	rm $(CHKR)
	rm $(PSHSWP)

re: fclean all

norm:
	norminette debug.c execution.c node_functions.c read_instructions.c checker.c error_handling.c push_swap.c validation.c

t0:
	./push_swap

t1:
	./push_swap 0

t2:
	./push_swap 0 1

t3: 
	./push_swap 1 0

t4:
	./push_swap 0 1 2

t5:
	./push_swap 0 2 1

t6:
	./push_swap 1 0 2

t7:
	./push_swap 1 2 0

t8:
	./push_swap 2 0 1

t9:
	./push_swap 2 1 0

test_all: t1 t2 t3 t4 t5 t6 t7 t8 t9