/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:20:55 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/24 16:44:17 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_median(t_node *stack, int len)
{
	int i;
	int min;
	int max;

	i = 0;
	min = stack->norm;
	max = stack->norm;
	while (i < len)
	{
		if (min < stack->norm)
			min = stack->norm;
		if (max > stack->norm)
			max = stack->norm;
		i++;
		stack = stack->next;
	}
	return ((max + min) / 2);
}

int		target_node(t_node *stack, int median, int len)
{
	int i;

	i = 0;
	while (i < len && stack->next)
	{
		if (stack->norm <= median)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int		main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr_args;

	arr_args = initialize_arguments(argc, argv);
	validate_args(arr_args);
	init_lists(&stack_a, &stack_b, arr_args);
	check_for_duplicates(stack_a);
	normalize_values(&stack_a);
	quick_sort(&stack_a, &stack_b, stack_len(stack_a), 1);
	print_stacks(stack_a, stack_b);
}
