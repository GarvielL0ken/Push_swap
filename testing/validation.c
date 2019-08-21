/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:28:22 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/21 12:35:48 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_instruction(const char *str)
{
	char	**arr;
	int		i;

	i = -1;
	arr = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	while (++i < 11)
	{
		if (!ft_strcmp(str, arr[i]))
			return (1);
	}
	return (0);
}

char	**initialize_arguments(int argc, char *argv[])
{
	char **arr_args;
	t_flag flags;

	arr_args = NULL;
	flags.dtld_err_msg = 1;
	if (argc == 2)
		arr_args = ft_strsplit(argv[1], ' ');
	else if (argc > 2)
	{
		arr_args = argv;
		arr_args++;
	}
	else
		print_err_msg("Error: Too few arguments", flags);
	return (arr_args);
}

void	validate_args(char **arr_args, t_flag flags)
{
	int	i;
	int	j;

	i = 0;
	while (ft_isdigit(arr_args[i][0]))
	{
		j = 0;
		while (arr_args[i][j])
		{
			if (!ft_isdigit(arr_args[i][j]))
				print_err_msg("Error: contains non digit characters", flags);
			j++;
		}
		i++;
	}
}

void	check_for_duplicates(t_node *stack, t_flag flags)
{
	t_node *compare;

	while (stack->next)
	{
		compare = stack->next;
		while (compare)
		{
			if (stack->n == compare->n)
				print_err_msg("Error: argument duplicated", flags);
			compare = compare->next;
		}
		stack = stack->next;
	}
}

void	validate_results(t_node *stack_a, t_node *stack_b)
{
	t_node *node;

	if (!stack_a || stack_b)
	{
		ft_putstr("KO\n");
		exit(1);
	}
	if (!stack_a->next)
	{
		ft_putendl("OK");
		exit(1);
	}
	node = stack_a;
	while (node->next)
	{
		if (node->n > node->next->n)
		{
			printf("KO\n");
			exit(1);
		}
		node = node->next;
	}
}
