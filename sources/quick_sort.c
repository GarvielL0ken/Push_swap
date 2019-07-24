/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:32:30 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/24 16:35:20 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		base_case(t_node **stack_a, t_node **stack_b, int len, int mode)
{
	if (len == 2 && mode == 1 && (*stack_a)->n > (*stack_a)->n)
		swap(stack_a);
	if (len == 2 && mode == -1 && (*stack_b)->n < (*stack_b)->n)
		swap(stack_b);
	if (len <= 2)
		return (1);
	return (0);
}

void	quick_sort(t_node **stack_a, t_node **stack_b, int len, int mode)
{
	int	median;
	int	rotations;
	int	count;

	if (base_case(stack_a, stack_b, len, mode))
		return ;
	median = find_median(*stack_a, len);
	rotations = target_node(*stack_a, median, len);
	count = 0;
	while (rotations != -1)
	{
		print_stacks(*stack_a, *stack_b);
		printf("rotations = %d\nlen = %d\n", rotations, len);
		while (rotations)
		{
			rotate(stack_a);
			rotations--;
		}
		push(stack_b, stack_a);
		count++;
		rotations = target_node(*stack_a, median, len);
	}
	printf("count = %d\nmode = %d\n", count, mode);
}
