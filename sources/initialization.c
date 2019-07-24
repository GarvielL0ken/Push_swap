/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:43:48 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/24 16:50:07 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	normalize_values(t_node **stack_a)
{
	t_node	*primary;
	t_node	*secondary;
	int		max;

	max = stack_len(*stack_a) - 1;
	primary = *stack_a;
	while (primary)
	{
		primary->norm = max;
		secondary = *stack_a;
		while (secondary)
		{
			if (primary->n < secondary->n)
				primary->norm--;
			secondary = secondary->next;
		}
		primary = primary->next;
	}
}
