/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:13:12 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/28 12:12:50 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_flag	init_flags(void)
{
	t_flag	flags;

	flags.print_cmd_count = 0;
	flags.cmd_count = 0;
	flags.debug = 0;
	flags.dtld_err_msg = 0;
	flags.exit_code = EXIT_CODE;
	flags.help = 0;
	flags.invalid = 0;
	flags.vis = 0;
	return (flags);
}

t_flag	set_flag(t_flag flags, char f)
{
	if (f == 'c')
		flags.print_cmd_count = 1;
	else if (f == 'd')
		flags.debug = 1;
	else if (f == 'e')
		flags.dtld_err_msg = 1;
	else if (f == 'h')
		flags.help = 1;
	else if (f == 'v')
		flags.vis = 1;
	else
	{
		flags.invalid = 1;
		flags.help = 1;
	}
	return (flags);
}

t_flag	set_flags(char **arr_args)
{
	int		i;
	int		j;
	t_flag	flags;

	i = 0;
	flags = init_flags();
	while (arr_args[i])
	{
		if (arr_args[i][0] == '-' && ft_isalpha(arr_args[i][1]))
		{
			j = 1;
			while (arr_args[i][j])
			{
				flags = set_flag(flags, arr_args[i][j]);
				j++;
			}
		}
		i++;
	}
	return (flags);
}

void	check_flags(t_flag flags)
{
	if (flags.invalid)
		ft_putendl(KRED "INVALID OPTION" KRESET);
	if (flags.help)
		display_help();
}
