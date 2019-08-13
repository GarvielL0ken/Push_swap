/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:22:58 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/13 10:30:00 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_last(t_node *stack, int mode)
{
	while (stack->next)
		stack = stack->next;
	if (!mode)
		return (stack->n);
	else
		return (stack->norm);
}
