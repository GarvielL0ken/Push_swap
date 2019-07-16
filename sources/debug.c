/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:26:37 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/16 16:25:43 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	debug_str(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		printf("str[%d] = %c : %d\n", i, str[i], str[i]);
}

void	print_list(t_node *node, int mode)
{
	int	i;

	i = 0;
	while (node)
	{
		ft_putstr("node_");
		ft_putnbr(i);
		ft_putstr("->n = ");
		if (!mode)
			ft_putnbr(node->n);
		else if (mode == 1)
			ft_putnbr(node->norm);
		ft_putchar('\n');
		node = node->next;
		i++;
	}
}

void	print_stacks(t_node *node_1, t_node *node_2)
{
	int i;

	i = 0;
	while (node_1 || node_2)
	{
		if (node_1)
		{
			printf("node_1[%d]->n = %d\t", i, node_1->n);
			node_1 = node_1->next;
		}
		else
			printf("                  \t");
		if (node_2)
		{
			printf("node_2[%d]->n = %d", i, node_2->n);
			node_2 = node_2->next;
		}
		printf("\n");
		i++;
	}
}
