/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:54:30 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/26 13:37:58 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		set_upper_bound(t_node *s, int u_b, int r)
{
	while (s)
	{
		if (s->norm < u_b)
			return (u_b);
		s = s->next;
	}
	u_b += r;
	return (u_b);
}

void	rot(t_node **s, int rots)
{
	while (rots)
	{
		if (rots > 0)
		{
			rotate(s, 1);
			rots--;
		}
		else
		{
			rev_rotate(s, 1);
			rots++;
		}
	}
}

int		rot_and_swap(t_node **a, t_node **b, int rots)
{
	int ss;

	rot(a, rots);
	ss = 1;
	if (stack_len(*b) >= 2)
	{
		if ((*b)->n < stack_last(*b, 0))
			rotate(b, 2);
		if ((*b)->n < (*b)->next->n)
		{
			if ((*b)->next->n - (*b)->n > (*b)->n - stack_last(*b, 0))
				rotate(b, 2);
			if ((*a)->next->n < stack_last(*a, 0) && (*a)->next->n < (*a)->n)
				ss = 3;
			if (ss == 3)
				swap(b, 0);
			else
				swap(b, 2);
		}
	}
	return (ss);
}

void	post_p_s(t_node **a, t_node **b, int size)
{
	if (stack_len(*b) >= 2)
	{
		if ((*b)->next->n - (*b)->n > (*b)->n - stack_last(*b, 0))
			rotate(b, 2);
		if ((*b)->n < stack_last(*b, 0))
			rotate(b, 2);
		if ((*b)->n < (*b)->next->n)
			swap(b, 2);
	}
	if (size == 3)
		sort_3(a);
	else if (size == 2)
	{
		if ((*a)->n > (*a)->next->n)
			swap(a, 1);
	}
}

void	priority_sort(t_node **s_a, t_node **s_b, int size)
{
	int ss;
	int range;
	int upper_bound;
	int rots;

	upper_bound = (stack_len(*s_a) <= 100) ? RANGE_LOW : RANGE_HIGH;
	range = upper_bound;
	while (size > 3)
	{
		if (sorted(*s_a))
			break ;
		upper_bound = set_upper_bound(*s_a, upper_bound, range);
		rots = nearest(*s_a, upper_bound);
		ss = rot_and_swap(s_a, s_b, rots);
		if ((*s_a)->n < (*s_a)->next->n && (*s_a)->n < stack_last(*s_a, 0))
		{
			push(s_b, s_a, 2);
			size--;
		}
		else if ((*s_a)->next->n < stack_last(*s_a, 0))
			swap(s_a, ss);
		else
			rev_rotate(s_a, 1);
	}
	post_p_s(s_a, s_b, size);
}
