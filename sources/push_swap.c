/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:20:55 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/02 11:28:28 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		stack_last(t_node *stack, int mode)
{
	while (stack->next)
		stack = stack->next;
	if (!mode)
		return (stack->n);
	else
		return (stack->norm);
}

int sorted(t_node *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->norm > stack_a->next->norm)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int		find_nearest(t_node *s_a, int max, int size)
{
	int i;
	int first;
	int last;

	first = -1;
	last = -1;
	i = -1;
	if (s_a->norm < max || s_a->next->norm < max || stack_last(s_a, 1) < max)
		return (0);
	while (s_a)
	{
		if (s_a->n < max && first == -1)
			first = i;
		else if (s_a->n < max)
			last = i;
		i++;
		s_a = s_a->next;
	}
	last = size - last - 2;
	if (first < last)
		return (first);
	else if (first == -1)
		return (0);
	else
		return (-last);
	printf("size = %d\nfirst = %d\nlast = %d\nsize - last - 2 = %d\n", size, first, last, size - last - 2);
}

int		less_than_max(t_node *s, int max)
{
	while (s)
	{
		if (s->norm < max)
			return (1);
		s = s->next;
	}
	return (0);
}

void	set_3(t_node *s_a, int *a, int *b, int *c)
{
	*a = s_a->norm;
	*b = s_a->next->norm;
	*c = s_a->next->next->norm;
}

void	sort_3(t_node **s_a)
{
	int a;
	int b;
	int c;

	set_3(*s_a, &a, &b, &c);
	if (c < b && b < a) //210
		swap(s_a, 1);
	set_3(*s_a, &a, &b, &c);
	if ((a < c && c < b) || (c < a && a < b)) //021 || 120
		rev_rotate(s_a, 1);
	set_3(*s_a, &a, &b, &c);
	if (b < a && a < c) //102
		swap(s_a, 1);
	set_3(*s_a, &a, &b, &c);
	if (b < c && c < a) //201
		rotate(s_a, 1);

}

void	priority_sort(t_node **s_a, t_node **s_b, int size)
{
	int ss;

	while (size > 3)
	{
		ss = 1;
		if (stack_len(*s_b) >= 2)
		{
			if ((*s_b)->n < stack_last(*s_b, 0))
				rotate(s_b, 2);
			if ((*s_b)->n < (*s_b)->next->n)
			{
				/*(if ((*s_b)->next->n - (*s_b)->n > (*s_b)->n - stack_last(*s_b, 0))
					rotate(s_b, 2);*/
				if ((*s_a)->next->n < stack_last(*s_a, 0) && (*s_a)->next->n < (*s_a)->n)
					ss = 3;
				if (ss == 3)
					swap(s_b, 0);
				else
					swap(s_b, 2);
			}
		}
		if ((*s_a)->n < (*s_a)->next->n && (*s_a)->n < stack_last(*s_a, 0))
		{
			push(s_b, s_a, 2);
			size--;
		}
		else if ((*s_a)->next->n < stack_last(*s_a, 0))
			swap(s_a, ss);
		else
			rev_rotate(s_a, 1);
	}
	if (stack_len(*s_b) >= 2)
	{
		/*if ((*s_b)->next->n - (*s_b)->n > (*s_b)->n - stack_last(*s_b, 0))
			rotate(s_b, 2);*/
		if ((*s_b)->n < stack_last(*s_b, 0))
			rotate(s_b, 2);
		if ((*s_b)->n < (*s_b)->next->n)
			swap(s_b, 2);
	}
	if (size == 3)
		sort_3(s_a);
	else if (size == 2)
	{
		if ((*s_a)->n > (*s_a)->next->n)
			swap(s_a, 1);
	}
}

void	selection_sort(t_node **s_a, t_node **s_b, int size)
{
	int ss;
	while (size)
	{
		ss = 0;
		if ((*s_b)->next)
		{
			if ((*s_b)->n < (*s_b)->next->n)
			{
				swap(s_b, 0);
				ss += 2;
			}
		}
		if ((*s_a)->next->n < (*s_a)->n)
		{
			swap(s_a, 0);
			ss++;
		}
		if (ss == 1)
			ft_putstr("sa\n");
		else if (ss == 2)
			ft_putstr("sb\n");
		else if (ss == 3)
			ft_putstr("ss\n");
		//print_stacks(*s_a, *s_b, 0);
		//if (ss == 0)
		//	printf("\n");
		push(s_a, s_b, 1);
		//print_stacks(*s_a, *s_b, 0);
		size--;
	}
	if ((*s_a)->next->n < (*s_a)->n)
			swap(s_a, 1);

}

int		cost(t_node *s_a)
{
	int i;
	int n;
	int cost;

	i = 0;
	cost = 0;
	while (s_a)
	{
		n = s_a->norm;
		n -= i;
		if (n < 0)
			n *= -1;
		cost += n;
		i++;
		s_a = s_a->next;
	}
	return (cost);
}

int		main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**arr_args;
	int initial_cost;

	arr_args = initialize_arguments(argc, argv);
	validate_args(arr_args);
	init_lists(&stack_a, &stack_b, arr_args);
	check_for_duplicates(stack_a);
	normalize_values(&stack_a);
	initial_cost = cost(stack_a);
	if (!sorted(stack_a))
	{
		priority_sort(&stack_a, &stack_b, stack_len(stack_a));
		selection_sort(&stack_a, &stack_b, stack_len(stack_b));
	}
	/*while (stack_len(stack_b))
	{
		if (stack_b->next)
		{
			if (stack_b->n < stack_b->next->n)
				swap(&stack_b, 2);
		}
		push(&stack_a, &stack_b, 1);
	}*/
	//print_stacks(stack_a, stack_b, 0);
	printf("initial_cost = %d\ncost = %d\n", initial_cost, cost(stack_a));
}
