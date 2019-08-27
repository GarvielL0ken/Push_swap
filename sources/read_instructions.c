/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 09:41:23 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/27 10:32:31 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**read_instructions(t_flag flags)
{
	char	**arr_instructions;
	char	*str_1;
	char	*str_2;
	char	*tmp;

	str_2 = ft_strnew(1);
	while (1)
	{
		get_next_line(0, &str_1);
		if (str_1[0] == '\0')
			break ;
		if (!check_instruction(str_1))
			print_err_msg("Error, Instruction Invalid", flags);
		tmp = str_2;
		str_2 = ft_strjoin(str_2, str_1);
		free(str_1);
		free(tmp);
		tmp = str_2;
		str_2 = ft_strjoin(str_2, " ");
		free(tmp);
	}
	arr_instructions = ft_strsplit(str_2, ' ');
	free(str_2);
	return (arr_instructions);
}
