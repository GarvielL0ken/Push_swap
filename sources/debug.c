/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:26:37 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/26 14:38:21 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_cmd_count(int cmd_count)
{
	ft_putstr("Number of instructions used: ");
	ft_putnbr(cmd_count);
	ft_putchar('\n');
}

void	draw_box_char(int c)
{
	unsigned char buff[4];

	if (c < 0x800)
	{
		buff[0] = 0xc0 | (c >> 6);
		buff[1] = 0x80 | (c >> 0 & 0x3f);
		write(1, buff, 2);
	}
	else if (c < 0x10000)
	{
		buff[0] = 0xe0 | (c >> 12);
		buff[1] = 0x80 | (c >> 6 & 0x3f);
		buff[2] = 0x80 | (c >> 0 & 0x3f);
		write(1, buff, 3);
	}
	else
	{
		buff[0] = 0xf0 | (c >> 18);
		buff[1] = 0x80 | (c >> 12 & 0x3f);
		buff[2] = 0x80 | (c >> 6 & 0x3f);
		buff[3] = 0x80 | (c >> 0 & 0x3f);
		write(1, buff, 4);
	}
}

void	print_elem(int w, t_node *s)
{
	int i;

	i = 0;
	while (i < w + 2)
	{
		if (s)
		{
			if (w - width(s->n) < i)
			{
				ft_putnbr(s->n);
				i += width(s->n);
			}
		}
		ft_putchar(' ');
		i++;
	}
	draw_box_char(V);
}

int		width(int n)
{
	int w;

	w = 1;
	if (n < 0)
	{
		n *= -1;
		w++;
	}
	while (n >= 10)
	{
		n /= 10;
		w++;
	}
	return (w);
}

void	debug(t_node *a, t_node *b, char *s)
{
	int w;

	w = max_width(a, b);
	ft_putendl(s);
	print_border(w, 0);
	while (a || b)
	{
		draw_box_char(V);
		print_elem(w, a);
		print_elem(w, b);
		ft_putchar('\n');
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	print_border(w, 1);
}
