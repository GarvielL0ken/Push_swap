/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:34:03 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/09 15:46:14 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include "libft/libft.h"

int	check_instruction(const char *str)
{
	char	arr[12][4] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	int		i;

	i = 0;
	arr[11][0] = '\0';
	while (arr[i][0] != '\0')
	{
		if (!ft_strcmp(str, arr[i]))
			return (1);
		i++;
	}
	return (0);
}

int	print_err_msg(const char *err_msg)
{
	ft_putendl_fd(err_msg, 2);
	return (0);
}

void debug_str(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		printf("str[%d] = %c : %d'\n", i, str[i], str[i]);
}

t_node	*create_head(int n)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node))
}

int	main(int argc, char *argv[])
{
	t_node	*head;
	t_node	*next;
	char	**args;
	char	*str;
	int		i;
	int		j;

	/*INITIALIZE ARGS*/
	i = 1;
	if (argc == 2)
		args = ft_strsplit(argv[i], ' ');
	else if (argc > 2)
	{
		args = argv;
		args++;
	}
	else
		return (print_err_msg("Error: TOO FEW ARGUMENTS"));
	
	/*INITIALIZE HEAD*/
	head = (t_node *)malloc(sizeof(t_node));
	head->n = args[0];
	head->next = NULL;
	next = head;
	i = 1;
	while (args[i])
	{
		next->next = (t_node
	}
	/*VALIDATE ARGS*/
	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (print_err_msg("Error"));
			j++;
		}
		i++;
	}
	
	/*READ INSTRUCTIONS*/
	while (1)
	{
		get_next_line(0, &str);
		if (str[0] == '\0')
			break ;
		else if (!check_instruction(str))
			return (print_err_msg("Error, Instruction Invlaid"));
	}
	printf("here goes the OK || KO\n");
}
