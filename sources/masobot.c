/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masobot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:44:24 by jsarkis           #+#    #+#             */
/*   Updated: 2019/10/09 02:16:20 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

float       *get_values(t_node *stack_a)
{
    t_node  *current;
    float   *arr_values;
    int     i;

    current = stack_a;
    arr_values = (float *)malloc(sizeof(float) * NUM_INPUTS);
    i = 0;
    while (current)
    {
        arr_values[i] = (float)current->norm;
        current = current->next;
        i++;
    }
    return (arr_values);
}

float       *initialize_weights(int num_weights)
{
    float *arr_weights;
    int i;

    arr_weights = (float *)malloc(sizeof(float) * num_weights);
    for (i = 0; i < num_weights; i++)
        arr_weights[i] = ((float)rand()/(float)(RAND_MAX));
    return (arr_weights);
}

t_masonode  *initialize_node(float value, int num_weights, float bias)
{
    t_masonode *node_new;

    node_new = (t_masonode *)malloc(sizeof(t_masonode));
    node_new->value = value;
    node_new->weights = initialize_weights(num_weights);
    node_new->bias = bias;
    return(node_new);
}

t_masonode  **initialize_layer(int size, float *arr_values, int num_weights, float *arr_biases, int mode)
{
    t_masonode **lyr_new;
    int i;

    if (size)
        lyr_new = (t_masonode **)malloc(sizeof(t_masonode *) * size);
    for (i = 0; i < size; i++)
    {
        if (mode == 1)
            lyr_new[i] = initialize_node(arr_values[i], num_weights, 0);
        else if (mode == 2)
            lyr_new[i] = initialize_node(arr_values[i], num_weights, arr_biases[i]);
        else
            lyr_new[i] = initialize_node(0, num_weights, 0);
    }
    return (lyr_new);
}

void        print_weights(float *arr_weights, int num_weights)
{
    int i;

    for (i = 0; i < num_weights; i++)
        printf("arr_weights[%d]: %f\n", i, arr_weights[i]);
}

void        print_layer(t_str str_layer, int size, t_masonode **lyr_layer, int num_weights)
{
    int i;

    printf("%s\n", str_layer);
    for (i = 0; i < size; i++)
    {
        printf("%d\nvalue: %f\n", i, lyr_layer[i]->value);
        print_weights(lyr_layer[i]->weights, num_weights);
        printf("bias: %f\n", lyr_layer[i]->bias);
        printf("\n");
    }
}

void        print_bot(t_masobot bot)
{
    print_layer("Input Layer", NUM_INPUTS, bot.lyr_inputs, NUM_HIDDEN_1);
    print_layer("Hidden Layer-1", NUM_HIDDEN_1, bot.lyr_hidden_1, NUM_OUTPUTS);
    print_layer("Output Layer", NUM_OUTPUTS, bot.lyr_outputs, 0);
}

float       weighted_sum(t_masonode **lyr_layer, int layer_size, int weight_index)
{
    float   f_new;
    int     i;

    f_new = 0;
    for (i = 0; i < layer_size; i++)
        f_new += lyr_layer[i]->value * lyr_layer[i]->weights[weight_index];
    return (f_new);
}

void        propagate_layer_forward(t_masonode **lyr_prev, int prev_size, t_masonode ***lyr_current, int current_size)
{
    float   f_new;
    int     i;

    for (i = 0; i < current_size; i++)
    {
        f_new = weighted_sum(lyr_prev, prev_size, i);
        f_new += (*lyr_current)[i]->bias;
        f_new = tanh(f_new);
        (*lyr_current)[i]->value = f_new;
    }
}

int         most_significant(t_masonode **lyr_outputs)
{
    float   n;
    int     index;
    int     i;

    n = lyr_outputs[0]->value;
    index = 0;
    for (i = 1; i < NUM_OUTPUTS; i++)
    {
        if (lyr_outputs[i]->value > n)
        {
            n = lyr_outputs[i]->value;
            index = i;
        }
    }
    return (index);
}

void        print_command(t_masonode **lyr_outputs)
{
    t_str arr_cmds[] = {"sa", "ra", "sorted"};
    
    ft_putstr(arr_cmds[most_significant(lyr_outputs)]);
    ft_putchar('\n');
}

void        masobot(t_node **stack_a)
{
    t_masobot   bot;
    float         *arr_values;

    arr_values = get_values(*stack_a);
    bot.lyr_inputs = initialize_layer(NUM_INPUTS, arr_values, NUM_HIDDEN_1, NULL, 1);
    bot.lyr_hidden_1 = initialize_layer(NUM_HIDDEN_1, NULL, NUM_OUTPUTS, NULL, 0);
    bot.lyr_outputs = initialize_layer(NUM_OUTPUTS, NULL, 0, NULL, 0);
    propagate_layer_forward(bot.lyr_inputs, NUM_INPUTS, &(bot.lyr_hidden_1), NUM_HIDDEN_1);
    propagate_layer_forward(bot.lyr_hidden_1, NUM_HIDDEN_1, &(bot.lyr_outputs), NUM_OUTPUTS);
    print_bot(bot);
    print_command(bot.lyr_outputs);
}