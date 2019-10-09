# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 11:42:07 by jsarkis           #+#    #+#              #
#    Updated: 2019/10/08 22:03:07 by jsarkis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CHKR = checker
PSHSWP = push_swap
HEADER = ../includes/push_swap.h

CFLAGS = -Wall -Werror -Wextra
LINK = -L./libft -lft
SRCS = commands.c \
	   debug.c \
	   display_help.c \
	   draw.c \
	   error_handling.c \
	   execution.c \
	   flags.c \
	   init_lists.c \
	   initialization.c \
	   min.c \
	   nearest.c \
	   node_functions.c \
	   priority_sort.c \
	   read_instructions.c \
	   selection_sort.c \
	   sort_3.c \
	   sorted.c \
	   stack_last.c \
	   validation.c \
	   masobot.c
	   

LIB = libft/libft.a

all: $(LIB) $(PSHSWP) $(CHKR) $(HEADER) 

$(LIB):
	make -C libft

$(PSHSWP): push_swap.c $(SRCS) $(HEADER)
	gcc $(CFLAGS) push_swap.c $(SRCS) $(LINK) -o $(PSHSWP)

$(CHKR): checker.c $(SRCS) $(HEADER)
	gcc $(CFLAGS) checker.c $(SRCS) $(LINK) -o $(CHKR)

fclean:
	rm $(CHKR)
	rm $(PSHSWP)
	make -C libft fclean

re: fclean all

norm:
	norminette push_swap.c checker.c $(SRCS)

t0:
	./push_swap

t1:
	./push_swap 0 | ./checker 0

t2:
	./push_swap 0 1 | ./checker 0 1

t3: 
	./push_swap 1 0 | ./checker 1 0

t4:
	./push_swap 0 1 2 | ./checker 0 1 2

t5:
	./push_swap 0 2 1 | ./checker 0 2 1

t6:
	./push_swap 1 0 2 | ./checker 1 0 2

t7:
	./push_swap 1 2 0 | ./checker 1 2 0

t8:
	./push_swap 2 0 1 | ./checker 2 0 1

t9:
	./push_swap 2 1 0 | ./checker 2 1 0

t10:
	./push_swap 0 1 2 3 | ./checker 0 1 2 3

t11:
	./push_swap 0 1 3 2 | ./checker 0 1 3 2

t12:
	./push_swap 0 2 1 3 | ./checker 0 2 1 3

t13:
	./push_swap 0 2 3 1 | ./checker 0 2 3 1

t14:
	./push_swap 0 3 1 2 | ./checker 0 3 1 2

t15:
	./push_swap 0 3 2 1 | ./checker 0 3 2 1

t16:
	./push_swap 1 0 2 3 | ./checker 1 0 2 3

t17:
	./push_swap 1 0 3 2 | ./checker 1 0 3 2

t18:
	./push_swap 1 2 0 3 | ./checker 1 2 0 3

t19:
	./push_swap 1 2 3 0 | ./checker 1 2 3 0

t20:
	./push_swap 1 3 0 2 | ./checker 1 3 0 2

t21:
	./push_swap 1 3 2 0 | ./checker 1 3 2 0

t22:
	./push_swap 2 0 1 3 | ./checker 2 0 1 3

t23:
	./push_swap 2 0 3 1 | ./checker 2 0 3 1

t24:
	./push_swap 2 1 0 3 | ./checker 2 1 0 3

t25:
	./push_swap 2 1 3 0 | ./checker 2 1 3 0

t26:
	./push_swap 2 3 0 1 | ./checker 2 3 0 1

t27:
	./push_swap 2 3 1 0 | ./checker 2 3 1 0

t28:
	./push_swap 3 0 1 2 | ./checker 3 0 1 2

t29:
	./push_swap 3 0 2 1 | ./checker 3 0 2 1

t30:
	./push_swap 3 1 0 2 | ./checker 3 1 0 2

t31:
	./push_swap 3 1 2 0 | ./checker 3 1 2 0

t32:
	./push_swap 3 2 0 1 | ./checker 3 2 0 1

t33:
	./push_swap 3 2 1 0 | ./checker 3 2 1 0

test_3: t4 t5 t6 t7 t8 t9

test_4: t10 t11 t12 t13 t14 t15 t16 t17 t18 t19 t20 t21 t22 t23 t24 t25 t26 t27 t28 t29 t30 t31 t32 t33

test_5: 
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG
