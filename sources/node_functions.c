/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:03:24 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/26 14:13:41 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_head(int n)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (head)
	{
		head->n = n;
		head->norm = -1;
		head->next = NULL;
	}
	return (head);
}

int		stack_len(t_node *stack)
{
	int len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
