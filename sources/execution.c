/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:01:47 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/15 15:31:06 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <sys/ioctl.h>

size_t	get_tw(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
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

int		width(int n)
{
	int w;

	w = 1;
	while (n >= 10)
	{
		n /= 10;
		w++;
	}
	return (w);
}

int		max_width(t_node *a, t_node *b)
{
	int n;

	n = max(a, b);
	return (width(n));
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

void	debug(t_node *a, t_node *b)
{
	int w;

	w = max_width(a, b);
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

void	draw_line(t_node *s, int w)
{
	int i;

	ft_putchar(' ');
	i = 0;
	if (s)
	{
		while (i++ <= (s)->n)
			draw_box_char(B);
	}
	else
		i++;
	while (i++ <= w + 1)
		ft_putchar(' ');
	draw_box_char(V);
}

void	draw(t_node *a, t_node *b)
{
	int w;

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

void	execute_all_cmds(char **arr, t_node **s_a, t_node **s_b)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		execute_cmd(arr[i], s_a, s_b);
		ft_putendl(arr[i]);
		draw(*s_a, *s_b);
		//debug(*s_a, *s_b);
		ft_putchar('\n');
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
