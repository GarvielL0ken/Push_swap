/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:34:03 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/09 11:38:47 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

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

int	main(int argc, char *argv[])
{
	char	**args;
	char	*str;
	int		i;
	int		j;

	i = 1;
	if (argc == 2)
		args = ft_strsplit(argv[i], ' ');
	else if (argc > 2)
	{
		args = argv;
		args++;
	}
	else
		return (0);

	i = 0;
	while (args[i])
	{
		//printf("string = %s\n", args[i]);
		j = 0;
		while (args[i][j])
		{
			//printf("char = %c : %d", args[i][j], args[i][j]);
			if (!ft_isdigit(args[i][j]))
				return (print_err_msg("Error"));
			//printf("\n");
			j++;
		}
		i++;
	}
	
	while (1)
	{
		get_next_line(0, &str);
		if (str[0] == '\0')
			break ;	
	}
	printf("here goes the OK || KO\n");
}
