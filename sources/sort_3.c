/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:35:03 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/13 10:45:54 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_3(t_node *s, int *a, int *b, int *c)
{
	*a = s->norm;
	*b = s->next->norm;
	*c = s->next->next->norm;
}

void	sort_3(t_node **s)
{
	int a;
	int b;
	int c;

	set_3(*s, &a, &b, &c);
	if ((a < c && c < b) || (b < a && a < c) || (c < b && b < a))
	{
		swap(s, 1);
		set_3(*s, &a, &b, &c);
	}
	if (c < a && a < b)
	{
		rev_rotate(s, 1);
		set_3(*s, &a, &b, &c);
	}
	if (b < c && c < a)
		rotate(s, 1);
}
