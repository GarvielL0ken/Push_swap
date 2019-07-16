/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:23:08 by jsarkis           #+#    #+#             */
/*   Updated: 2019/07/16 16:26:38 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../sources/libft/libft.h"
# include <stdio.h>

typedef struct			s_node
{
	int					n;
	int					norm;
	struct s_node		*next;
}						t_node;

int						check_instruction(const char *str);

t_node					*create_head(int n);

void					debug_str(char *str);

void					execute_all_cmds(char **arr, t_node **s_a, t_node **s_b);

void					execute_cmd(char const *cmd, t_node **s_a, t_node **s_b);

void					execute_cmd_cases(int i, t_node **s_a, t_node **s_b);

char					**initialize_arguments(int argc, char *argv[]);

void					init_lists(t_node **h_a, t_node **h_b, char **arr_args);

void					print_err_msg(const char *err_msg, int exit_code);

void					print_list(t_node *node, int mode);

void					print_stacks(t_node *node1, t_node *node_2);

void					push(t_node **stack_to, t_node **stack_from);

char					**read_instructions(void);

void					rev_rotate(t_node **head);

void					rotate(t_node **head);

void					swap(t_node **head);

void					validate_args(char **arr_args);

void					validate_results(t_node *stack_a, t_node *stack_b);
#endif
