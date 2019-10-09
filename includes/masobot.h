/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masobot.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarkis <jsarkis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:45:24 by jsarkis           #+#    #+#             */
/*   Updated: 2019/10/09 01:59:54 by jsarkis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASOBOT_H
# define MASOBOT_H
# define NUM_INPUTS 3
# define NUM_HIDDEN_1 2
# define NUM_OUTPUTS 3
# include "push_swap.h"
# include <math.h>

typedef char    *t_str;

typedef struct  s_masonode
{
    float       value;
    float       bias;
    float       *weights;
}               t_masonode;

typedef struct  s_masobot
{
    t_masonode  **lyr_inputs;
    t_masonode  **lyr_hidden_1;
    t_masonode  **lyr_outputs;
}               t_masobot;

#endif