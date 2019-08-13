/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:01:47 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/13 14:15:49 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int		max(t_node *a, t_node *b)
{
	int max;

	max = a->n;
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

int		width(int n)
{
	int width;

	width = 1;
	while (n)
	{
		if (n >= 10)
		{
			n /= 10;
			width++;
		}
		else
			n = 0;
	}
	return (width);
}

void	draw(t_node *a, t_node *b)
{
	int i;
	int w;

	i = 1;
	w = width(max(a, b)) * 2;
	printf("width = %d\n", w);
	draw_box_char(0x250c);
	draw_box_char(0x2500);
	while (i <= w)
	{
		draw_box_char(0x2500);
		if (w / 2 == i)
		{
			draw_box_char(0x2500);
			draw_box_char(0x252c);
			draw_box_char(0x2500);
		}
		i++;
	}
	draw_box_char(0x2500);
	draw_box_char(0x2510);
	ft_putchar('\n');
	while (a || b)
	{
		draw_box_char(0x2502);
		ft_putchar(' ');
		if (a)
		{
			ft_putnbr(a->n);
			a = a->next;
		}
		else
			ft_putchar(' ');
		ft_putchar(' ');
		draw_box_char(0x2502);
		ft_putchar(' ');
		if (b)
		{
			ft_putnbr(b->n);
			b = b->next;
		}
		else
			ft_putchar(' ');
		ft_putchar(' ');
		draw_box_char(0x2502);
		ft_putchar('\n');
	}
	i = 1;
	draw_box_char(0x2514);
	draw_box_char(0x2500);
	while (i <= w)
	{
		draw_box_char(0x2500);
		if (w / 2 == i)
		{
			draw_box_char(0x2500);
			draw_box_char(0x2534);
			draw_box_char(0x2500);
		}
		i++;
	}
	draw_box_char(0x2500);
	draw_box_char(0x2518);
	ft_putchar('\n');
}

void	execute_all_cmds(char **arr, t_node **s_a, t_node **s_b)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		execute_cmd(arr[i], s_a, s_b);
		ft_putendl(arr[i]);
		draw(*s_a, *s_b);
	}
}

void	execute_cmd(char const *cmd, t_node **s_a, t_node **s_b)
{
	char	**arr_cmds;
	int		i;

	i = 0;
	arr_cmds = ft_strsplit("sa sb ss ra rb rr rra rrb rrr pa pb", ' ');
	while (i < 12)
	{
		if (!ft_strcmp(cmd, arr_cmds[i]))
		{
			execute_cmd_cases(i, s_a, s_b);
			break ;
		}
		i++;
	}
}

void	execute_cmd_cases(int i, t_node **s_a, t_node **s_b)
{
	if ((i == 0 || i == 2) && *s_a)
		swap(s_a, 0);
	if ((i == 1 || i == 2) && *s_b)
		swap(s_b, 0);
	if ((i == 3 || i == 5) && *s_a)
		rotate(s_a, 0);
	if ((i == 4 || i == 5) && *s_b)
		rotate(s_b, 0);
	if ((i == 6 || i == 8) && *s_a)
		rev_rotate(s_a, 0);
	if ((i == 7 || i == 8) && *s_b)
		rev_rotate(s_b, 0);
	if (i == 9 && *s_b)
		push(s_a, s_b, 0);
	if (i == 10 && *s_a)
		push(s_b, s_a, 0);
}
