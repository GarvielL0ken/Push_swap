/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:41:33 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/13 11:41:37 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		nearest_ret(int f, int last, int len)
{
	f--;
	last = len - last - 1;
	if (f <= last)
		return (f);
	else
		return (last * (-1));
}

int		nearest(t_node *s, int u_b)
{
	int i;
	int first;
	int last;
	int len;

	if (s->norm < u_b || s->next->norm < u_b || stack_last(s, 1) < u_b)
		return (0);
	i = 0;
	first = -1;
	last = -1;
	len = stack_len(s);
	while (s)
	{
		if (s->norm < u_b && first == -1)
			first = i;
		if (s->norm < u_b)
			last = i;
		s = s->next;
		i++;
	}
	return (nearest_ret(first, last, len));
}
