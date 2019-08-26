/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:34:03 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/26 14:08:29 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr_args;
	char	**arr_instructions;
	t_flag	flags;

	arr_args = initialize_arguments(argc, argv);
	flags = set_flags(arr_args);
	if (flags.invalid)
		ft_putendl(KRED "INVALID OPTION" KRESET);
	if (flags.help)
		display_help();
	else
	{
		validate_args(arr_args, flags);
		init_lists(&stack_a, &stack_b, arr_args, flags);
		check_for_duplicates(stack_a, flags);
		normalize_values(&stack_a);
		arr_instructions = read_instructions(flags);
		flags = execute_all_cmds(arr_instructions, &stack_a, &stack_b, flags);
		validate_results(stack_a, stack_b);
		ft_putendl("OK");
		if (flags.print_cmd_count)
			display_cmd_count(flags.cmd_count);
	}
}
