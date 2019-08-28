/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:28:22 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/28 13:17:37 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_instruction(const char *str)
{
	char	**arr;
	int		found;
	int		i;

	found = 0;
	i = -1;
	arr = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	while (++i < 11 && !found)
	{
		if (!ft_strcmp(str, arr[i]))
			found = 1;
	}
	i = 0;
	free_arr(arr);
	return (found);
}

int		in_s(char c, const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

void	validate_args(char **arr_args, t_flag flags)
{
	int	i;
	int	j;

	i = 0;
	if (arr_args[0][0] == '-' && ft_isalpha(arr_args[0][1]))
		print_err_msg("Error: invalid syntax, use -h to see syntax", flags);
	while (arr_args[i])
	{
		if (arr_args[i][0] == '-' && ft_isalpha(arr_args[i][1]))
			break ;
		j = 0;
		while (arr_args[i][j])
		{
			if (!ft_isdigit(arr_args[i][j]) && !in_s(arr_args[i][j], " -"))
				print_err_msg("Error: contains non digit characters", flags);
			j++;
		}
		i++;
	}
	while (arr_args[i])
	{
		if (arr_args[i][0] != '-')
			print_err_msg("Error: invalid syntax, use -h to see syntax", flags);
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
