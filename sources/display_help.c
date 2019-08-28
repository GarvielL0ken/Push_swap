/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:21:08 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/26 13:53:49 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_help(void)
{
	ft_putendl("Usage:");
	ft_putendl("	./checker <space separated list of integers> <flags>\n");
	ft_putendl("	All integers must preceed all flags\n");
	ft_putendl("	The list of integers can be any combination of either");
	ft_putendl("	space separated integers and single strings ");
	ft_putendl("	for example 1 2 3, \"1 2 3\", \"1 2\" 3 are all valid");
	ft_putendl("");
	ft_putendl("	Flags must begin with a '-'\n");
	ft_putendl("Options/flags:");
	ft_putendl("	-c : Print number of instructions after a list is "
			"successfully sorted");
	ft_putendl("	-d : Debug mode, prints the stacks normalized values after"
			" each instruction");
	ft_putendl("	-e : Displays detailed error messages");
	ft_putendl("	-h : You got here didn't you? It's for this help text");
	ft_putendl("	-v : Visualize both stacks after each instruction");
}
