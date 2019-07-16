/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:28:22 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/15 10:38:33 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_instruction(const char *str)
{
	char	**arr;
	int		i;

	i = -1;
	arr = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	while (arr[++i][0] != '\0')
	{
		if (!ft_strcmp(str, arr[i]))
			return (1);
	}
	return (0);
}

char	**initialize_arguments(int argc, char *argv[])
{
	char **arr_args;

	arr_args = NULL;
	if (argc == 2)
		arr_args = ft_strsplit(argv[1], ' ');
	else if (argc > 2)
	{
		arr_args = argv;
		arr_args++;
	}
	else
		print_err_msg("Error: TOO FEW ARGUMENTS", 1);
	return (arr_args);
}

void	validate_args(char **arr_args)
{
	int	i;
	int	j;

	i = 0;
	while (arr_args[i])
	{
		j = 0;
		while (arr_args[i][j])
		{
			if (!ft_isdigit(arr_args[i][j]))
				print_err_msg("Error: argument does not contain only digits", \
					1);
			j++;
		}
		i++;
	}
}

void	validate_results(t_node *stack_a, t_node *stack_b)
{
	t_node *node;

	if (!stack_a || stack_b)
		print_err_msg("Error, stack a empty or stack b not empty", 1);
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
