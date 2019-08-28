/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:24:43 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/26 14:30:08 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		max(t_node *a, t_node *b)
{
	int max;

	if (a)
		max = a->n;
	else if (b)
		max = b->n;
	while (a || b)
	{
		if (a)
		{
			if (max < a->n)
				max = a->n;
			a = a->next;
		}
		if (b)
		{
			if (max < b->n)
				max = b->n;
			b = b->next;
		}
	}
	return (max);
}

int		max_width(t_node *a, t_node *b)
{
	int i;
	int j;

	i = max(a, b);
	j = min(a, b);
	if (width(i) > width(j))
		return (width(i));
	else
		return (width(j));
}

void	print_border(int w, int mode)
{
	int i;

	if (!mode)
		draw_box_char(TL);
	else
		draw_box_char(BL);
	i = 0;
	while (i < (w * 2) + 4)
	{
		draw_box_char(H);
		if (i == w + 1 && !mode)
			draw_box_char(TM);
		else if (i == w + 1)
			draw_box_char(BM);
		i++;
	}
	if (!mode)
		draw_box_char(TR);
	else
		draw_box_char(BR);
	ft_putchar('\n');
}

void	draw_line(t_node *s, int w)
{
	int i;

	ft_putchar(' ');
	i = 0;
	if (s)
	{
		while (i++ <= (s)->norm)
			draw_box_char(B);
	}
	else
		i++;
	while (i++ <= w + 1)
		ft_putchar(' ');
	draw_box_char(V);
}

void	draw(t_node *a, t_node *b, char *s)
{
	int w;

	usleep(50000);
	printf("\e[1;1H\e[2J");
	fflush(stdout);
	ft_putendl(s);
	w = max(a, b) + 1;
	print_border(w, 0);
	while (a || b)
	{
		draw_box_char(V);
		draw_line(a, w);
		draw_line(b, w);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		ft_putchar('\n');
	}
	print_border(w, 1);
}
