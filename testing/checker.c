/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 10:58:35 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/21 13:54:05 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_err_msg(const char *err_msg, t_flag flags)
{
	if (flags.dtld_err_msg)
		ft_putendl_fd(err_msg, 2);
	else
		ft_putendl_fd("Error", 2);
	exit(flags.exit_code);
}

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
		if (arr_args[i][0] == '-')
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

void	display_help(void)
{
	ft_putendl("Options/flags:");
	ft_putendl("	-c : Print number of instructions after a list is "
			"successfully sorted");
	ft_putendl("	-d : Debug mode, prints the stacks normalized values after"
			" each instruction");
	ft_putendl("	-e : Displays detailed error messages");
	ft_putendl("	-h : You got here didn't you? It's for this help text");
	ft_putendl("	-v : Visualize both stacks after each instruction");
}

int main(int argc, char *argv[])
{
	char 	**arr_args;
	t_flag	flags;

	arr_args = initialize_arguments(argc, argv);
	flags = set_flags(arr_args);
	if (flags.invalid)
		ft_putendl(KRED "Invalid option" KRESET);
	if (flags.help)
		display_help();
	else
	{
		validate_args(arr_args, flags);
	}
	//validate_args(arr_args, flags)
	//printf("valid\n");
}
