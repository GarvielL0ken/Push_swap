/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:29:33 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/26 14:05:51 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_node **stack_to, t_node **stack_from, int mode)
{
	t_node *first_from;

	first_from = *stack_from;
	if ((*stack_from)->next)
		*stack_from = (*stack_from)->next;
	else
		*stack_from = NULL;
	first_from->next = *stack_to;
	*stack_to = first_from;
	if (mode == 1)
		ft_putstr("pa\n");
	else if (mode == 2)
		ft_putstr("pb\n");
}

void	rev_rotate(t_node **head, int mode)
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
	if (mode == 1)
		ft_putstr("rra\n");
	else if (mode == 2)
		ft_putstr("rrb\n");
}

void	rotate(t_node **head, int mode)
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
	if (mode == 1)
		ft_putstr("ra\n");
	else if (mode == 2)
		ft_putstr("rb\n");
}

void	swap(t_node **head, int mode)
{
	if ((*head)->next)
	{
		swap_params(&((*head)->n), &((*head)->next->n));
		swap_params(&((*head)->norm), &((*head)->next->norm));
	}
	if (mode == 1)
		ft_putstr("sa\n");
	else if (mode == 2)
		ft_putstr("sb\n");
	else if (mode == 3)
		ft_putstr("ss\n");
}
