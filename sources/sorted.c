/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:30:32 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/26 13:45:01 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->norm + 1 != stack->next->norm)
			return (0);
		stack = stack->next;
	}
	return (1);
}
