# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 11:42:07 by jsarkis           #+#    #+#              #
#    Updated: 2019/07/09 12:00:11 by jsarkis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: checker

checker:
	gcc -Wall -Werror -Wextra checker.c -L./libft -lft -o checker

fclean:
	rm checker

re: fclean all
