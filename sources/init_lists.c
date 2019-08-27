/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:25:50 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/27 10:23:21 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*next_int(char *src)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(ft_find_index(src, ' ') + 1);
	while (src[i] != ' ' && src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	max_int(char *s, t_flag flags)
{
	if (ft_strlen(s) < 10)
		return ;
	else if (ft_strlen(s) > 10 || ft_strcmp(s, MAX_INT) > 0)
		print_err_msg("Error: integer larger than int max", flags);
}

char	*init_s(char **arr_args, int *i)
{
	char *s;

	*i = 0;
	s = arr_args[0];
	if (ft_find_index(s, ' ') == -1)
	{
		s = arr_args[1];
		*i = 1;
	}
	else
	{
		while (ft_find_index(s, ' ') != 0 && s)
			s++;
		s++;
	}
	return (s);
}

void	next_node(char *s, t_flag flags, t_node **node)
{
	char *tmp;

	tmp = next_int(s);
	max_int(tmp, flags);
	(*node)->next = create_head(ft_atoi(tmp));
	free(tmp);
	*node = (*node)->next;
}

void	init_lists(t_node **h_a, t_node **h_b, char **arr_args, t_flag flags)
{
	t_node	*node;
	char	*s;
	int		i;

	s = next_int(arr_args[0]);
	max_int(s, flags);
	*h_a = create_head(ft_atoi(s));
	free(s);
	node = *h_a;
	s = init_s(arr_args, &i);
	while (arr_args[i])
	{
		if (arr_args[i][0] == '-')
			break ;
		while (ft_find_index(s, ' ') != -1)
		{
			next_node(s, flags, &node);
			while (ft_find_index(s, ' ') > 0)
				s++;
			s++;
		}
		next_node(s, flags, &node);
		i++;
		if (arr_args[i])
			s = arr_args[i];
	}
	*h_b = NULL;
}
