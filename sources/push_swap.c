/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:20:55 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/27 09:59:44 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr_args;
	t_flag	flags;

	flags = init_flags();
	arr_args = initialize_arguments(argc, argv);
	validate_args(arr_args, flags);
	init_lists(&stack_a, &stack_b, arr_args, flags);
	check_for_duplicates(stack_a, flags);
	normalize_values(&stack_a);
	if (!sorted(stack_a))
	{
		priority_sort(&stack_a, &stack_b, stack_len(stack_a));
		selection_sort(&stack_a, &stack_b, stack_len(stack_b));
	}
}
