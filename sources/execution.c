/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:01:47 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/15 10:33:00 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	execute_all_cmds(char **arr, t_node **s_a, t_node **s_b)
{
	int	i;

	i = -1;
	while (arr[++i])
		execute_cmd(arr[i], s_a, s_b);
}

void	execute_cmd(char const *cmd, t_node **s_a, t_node **s_b)
{
	char	**arr_cmds;
	int		i;

	i = 0;
	arr_cmds = ft_strsplit("sa sb ss ra rb rr rra rrb rrr pa pb", ' ');
	while (i < 12)
	{
		if (!ft_strcmp(cmd, arr_cmds[i]))
		{
			execute_cmd_cases(i, s_a, s_b);
			break ;
		}
		i++;
	}
}

void	execute_cmd_cases(int i, t_node **s_a, t_node **s_b)
{
	if ((i == 0 || i == 2) && *s_a)
		swap(s_a);
	if ((i == 1 || i == 2) && *s_b)
		swap(s_b);
	if ((i == 3 || i == 5) && *s_a)
		rotate(s_a);
	if ((i == 4 || i == 5) && *s_b)
		rotate(s_b);
	if ((i == 6 || i == 8) && *s_a)
		rev_rotate(s_a);
	if ((i == 7 || i == 8) && *s_b)
		rev_rotate(s_b);
	if (i == 9 && *s_b)
		push(s_a, s_b);
	if (i == 10 && *s_a)
		push(s_b, s_a);
}
