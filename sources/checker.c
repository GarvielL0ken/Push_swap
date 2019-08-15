/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:34:03 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/15 10:00:38 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr_arguments;
	char	**arr_instructions;

	arr_arguments = initialize_arguments(argc, argv);
	validate_args(arr_arguments);
	init_lists(&stack_a, &stack_b, arr_arguments);
	check_for_duplicates(stack_a);
	arr_instructions = read_instructions();
	execute_all_cmds(arr_instructions, &stack_a, &stack_b);
	validate_results(stack_a, stack_b);
	ft_putendl("OK");
}
