/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:03:05 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/26 14:18:52 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		num_rots(t_node *s)
{
	int max;
	int n;
	int i;

	max = s->norm;
	i = 0;
	n = 0;
	while (s)
	{
		if (s->norm > max)
		{
			max = s->norm;
			n = i;
		}
		s = s->next;
		i++;
	}
	i--;
	if (i - n < n && n != 0)
		return (n - i - 1);
	else if (n > 0)
		return (n - 1);
	else
		return (0);
}

void	sorting_logic(t_node **s_a, t_node **s_b)
{
	int ss;

	ss = 0;
	if ((*s_b)->next)
	{
		if ((*s_b)->n < (*s_b)->next->n)
		{
			swap(s_b, 0);
			ss += 2;
		}
	}
	if ((*s_a)->next->n < (*s_a)->n)
	{
		swap(s_a, 0);
		ss++;
	}
	if (ss == 1)
		ft_putstr("sa\n");
	else if (ss == 2)
		ft_putstr("sb\n");
	else if (ss == 3)
		ft_putstr("ss\n");
}

void	selection_sort(t_node **s_a, t_node **s_b, int size)
{
	int rots;

	while (size)
	{
		sorting_logic(s_a, s_b);
		rots = num_rots(*s_b);
		while (rots)
		{
			if (rots < 0)
			{
				rev_rotate(s_b, 2);
				rots++;
			}
			else
			{
				rotate(s_b, 2);
				rots--;
			}
		}
		sorting_logic(s_a, s_b);
		push(s_a, s_b, 1);
		size--;
	}
	if ((*s_a)->next->n < (*s_a)->n)
		swap(s_a, 1);
}
