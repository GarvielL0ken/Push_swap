/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:06:26 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/28 13:06:28 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		min(t_node *a, t_node *b)
{
	int min;

	if (a)
		min = a->n;
	else if (b)
		min = b->n;
	while (a || b)
	{
		if (a)
		{
			if (min > a->n)
				min = a->n;
			a = a->next;
		}
		if (b)
		{
			if (min > b->n)
				min = b->n;
			b = b->next;
		}
	}
	return (min);
}
