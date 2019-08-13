/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:20:55 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/13 12:07:50 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr_args;
	//int		initial_cost;

	arr_args = initialize_arguments(argc, argv);
	validate_args(arr_args);
	init_lists(&stack_a, &stack_b, arr_args);
	check_for_duplicates(stack_a);
	normalize_values(&stack_a);
	//initial_cost = cost(stack_a);
	if (!sorted(stack_a))
	{
		priority_sort(&stack_a, &stack_b, stack_len(stack_a));
		selection_sort(&stack_a, &stack_b, stack_len(stack_b));
	}
}
