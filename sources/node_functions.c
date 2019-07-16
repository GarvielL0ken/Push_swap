/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:29:33 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/16 16:13:39 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "libft/libft.h"

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

void	push(t_node **stack_to, t_node **stack_from)
{
	t_node *first_from;

	first_from = *stack_from;
	if ((*stack_from)->next)
		*stack_from = (*stack_from)->next;
	else
		*stack_from = NULL;
	first_from->next = *stack_to;
	*stack_to = first_from;
}

void	rev_rotate(t_node **head)
{
	t_node *first;
	t_node *last;

	if ((*head)->next)
	{
		first = *head;
		last = *head;
		while (last->next->next)
			last = last->next;
		first = last->next;
		last->next = NULL;
		first->next = *head;
		*head = first;
	}
}

void	rotate(t_node **head)
{
	t_node *first;
	t_node *last;

	if ((*head)->next)
	{
		first = *head;
		last = *head;
		while (last->next)
			last = last->next;
		*head = (*head)->next;
		last->next = first;
		first->next = NULL;
	}
}

void	swap(t_node **head)
{
	if ((*head)->next)
	{
		swap_params(&((*head)->n), &((*head)->next->n));
		swap_params(&((*head)->norm), &((*head)->next->norm));
	}
}
