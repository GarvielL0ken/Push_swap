/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 09:41:23 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/27 14:57:35 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	read_instructions(t_flag flags, char ***arr)
{
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
		tmp = ft_strjoin(str_2, str_1);
		free(str_2);
		str_2 = tmp;
		tmp = ft_strjoin(str_2, " ");
		free(str_2);
		str_2 = tmp;
		free(str_1);
	}
	*arr = ft_strsplit(str_2, ' ');
	free(str_1);
	free(str_2);
}
