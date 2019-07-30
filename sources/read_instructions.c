/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 09:41:23 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/30 13:42:00 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**read_instructions(void)
{
	char	**arr_instructions;
	char	*str_1;
	char	*str_2;
	int		i;

	i = 0;
	str_2 = ft_strnew(1);
	while (1)
	{
		get_next_line(0, &str_1);
		if (str_1[0] == '\0')
			break ;
		if (!check_instruction(str_1))
			print_err_msg("Error, Instruction Invalid", 1);
		str_2 = ft_strjoin(str_2, str_1);
		str_2 = ft_strjoin(str_2, " ");
	}
	arr_instructions = ft_strsplit(str_2, ' ');
	return (arr_instructions);
}
