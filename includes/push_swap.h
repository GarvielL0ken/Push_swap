/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:23:08 by jsarkis           #+#    #+#             */
/*   Updated: 2019/08/06 15:09:37 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../sources/libft/libft.h"
# include <stdio.h>
# define RANGE_LOW 10
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

void					normalize_values(t_node **stack_a);

void					print_err_msg(const char *err_msg, int exit_code);

void					print_list(t_node *node, int mode);

void					print_stacks(t_node *node1, t_node *node_2, int mode);

void					push(t_node **stack_to, t_node **stack_from, int mode);

void					quick_sort(t_node **stack_a, t_node **stack_b, int len, int mode);

char					**read_instructions(void);

void					rev_rotate(t_node **head, int mode);

void					rotate(t_node **head, int mode);

int						stack_len(t_node *stack);

void					swap(t_node **head, int mode);

void					validate_args(char **arr_args);

void					validate_results(t_node *stack_a, t_node *stack_b);
#endif
