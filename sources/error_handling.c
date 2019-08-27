/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:51:10 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/27 13:13:49 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_err_msg(const char *err_msg, t_flag flags)
{
	if (flags.dtld_err_msg == 1)
		ft_putendl_fd(err_msg, 2);
	else if (!flags.dtld_err_msg)
		ft_putendl_fd("Error", 2);
	exit(flags.exit_code);
}

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&(arr[i]));
		i++;
	}
	free(arr);
}
