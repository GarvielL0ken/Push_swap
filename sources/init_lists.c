/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:25:50 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/15 10:26:12 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_lists(t_node **h_a, t_node **h_b, char **arr_args)
{
	t_node	*node;
	int		i;

	*h_a = create_head(ft_atoi(arr_args[0]));
	node = *h_a;
	i = 1;
	while (arr_args[i])
	{
		node->next = create_head(ft_atoi(arr_args[i]));
		node = node->next;
		i++;
	}
	*h_b = NULL;
}
