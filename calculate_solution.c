/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannes <hrother@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:51:11 by hannes            #+#    #+#             */
/*   Updated: 2023/10/27 19:56:28 by hannes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char *solve_3stack(t_stack *stack_a, t_stack *stack_b)
{
    char *str;

    if (stack_a->arr[0] == 0)
        str = exec_str(stack_a, stack_b, "");
    else if (stack_a->arr[1] == 0)
        str = exec_str(stack_a, stack_b, "rra\n");
    else if (stack_a->arr[2] == 0)
        str = exec_str(stack_a, stack_b, "ra\n");
    if (stack_a->arr[1] != 1)
        str = ft_strjoin(str, exec_str(stack_a, stack_b, "sa\n"));
    return (str);
} 

char *calculate_solution(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 3)
       return (solve_3stack(stack_a, stack_b)); 
    return (NULL);
}