/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:23:08 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/15 14:42:13 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../sources/libft/libft.h"
# include <stdio.h>
# define H 0x2500
# define V 0x2502
# define TL 0x250c
# define TR 0x2510
# define BL 0x2514
# define BR 0x2518
# define TM 0x252c
# define BM 0x2534
# define B 0x2580
# define KRED "\033[31m"
# define KGREEN "\033[32m"
# define RANGE_LOW 32
# define RANGE_HIGH 32

typedef struct			s_node
{
	int					n;
	int					norm;
	struct s_node		*next;
}						t_node;

int						base_case(t_node **stack_a, t_node **stack_b, int len, int mode);

void					check_for_duplicates(t_node *stack);

int						check_instruction(const char *str);

t_node					*create_head(int n);

void					debug_str(char *str);

void					execute_all_cmds(char **arr, t_node **s_a, t_node **s_b);

void					execute_cmd(char const *cmd, t_node **s_a, t_node **s_b);

void					execute_cmd_cases(int i, t_node **s_a, t_node **s_b);

char					**initialize_arguments(int argc, char *argv[]);

void					init_lists(t_node **h_a, t_node **h_b, char **arr_args);

int						nearest(t_node *s, int u_b);

void					normalize_values(t_node **stack_a);

int						num_rots(t_node *s);

void					print_err_msg(const char *err_msg, int exit_code);

void					print_list(t_node *node, int mode);

void					print_stacks(t_node *node1, t_node *node_2, int mode);

void					priority_sort(t_node **s_a, t_node **s_b, int size);

void					push(t_node **stack_to, t_node **stack_from, int mode);

void					quick_sort(t_node **stack_a, t_node **stack_b, int len, int mode);

char					**read_instructions(void);

void					rev_rotate(t_node **head, int mode);

void					rotate(t_node **head, int mode);

void					set_3(t_node *s, int *a, int *b, int *c);

int						set_upper_bound(t_node *s, int u_b, int r);

void					sort_3(t_node **s);

void					selection_sort(t_node **s_a, t_node **s_b, int size);

int						sorted(t_node *stack);

int						stack_last(t_node *stack, int mode);

int						stack_len(t_node *stack);

void					swap(t_node **head, int mode);

void					validate_args(char **arr_args);

void					validate_results(t_node *stack_a, t_node *stack_b);
#endif
