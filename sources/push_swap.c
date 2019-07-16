/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:20:55 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/16 16:53:35 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		stack_len(t_node *stack)
{
	int len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	normalize_values(t_node **stack_a)
{
	t_node	*primary;
	t_node	*secondary;
	int		max;

	max = stack_len(*stack_a) - 1;
	printf("max = %d\n", max);
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

int		main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr_args;

	arr_args = initialize_arguments(argc, argv);
	validate_args(arr_args);
	init_lists(&stack_a, &stack_b, arr_args);
	print_list(stack_a, 0);
	normalize_values(&stack_a);
	print_list(stack_a, 1);
	sort(&stack_a, &stack_b);
}
