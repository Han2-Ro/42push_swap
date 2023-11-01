/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannes <hrother@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:51:11 by hannes            #+#    #+#             */
/*   Updated: 2023/11/01 17:03:26 by hannes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_distance(t_stack *stack, int nbr)
{
    int i;

    i = 0;
    while (i < stack->size && stack->arr[i] != nbr)
        i++;
    if (i >= stack->size)
        return (-1);
    else if (i < stack->size / 2)
        return (i + 1);
    else
        return (stack->size - i - 1);
}

char *solve_3stack(t_stack *stack_a, t_stack *stack_b)
{
    char *str;

    str = "";
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

char *push_nbr_b(t_stack *stack_a, t_stack *stack_b, int nbr)
{
    char    *result;
    int     i;
    char    *ra;

    result = malloc(sizeof(char));
    result[0] = '\0';
    i = 0;
    while (i < stack_a->size && stack_a->arr[i] != nbr)
        i++;
    if (i >= stack_a->size)
        return (result);
    else if (i < stack_a->size / 2)
        ra = "rra\n";
    else
        ra = "ra\n";
    while (stack_a->arr[stack_a->size - 1] != nbr)
    {
        ft_strattach(&result, exec_str(stack_a, stack_b, ra));
    }
    ft_strattach(&result, exec_str(stack_a, stack_b, "pb\n"));
    return (result);
}

char *calculate_solution(t_stack *stack_a, t_stack *stack_b)
{
    char    *result;
    int     i;

    result = malloc(sizeof(char));
    result[0] = '\0';
    while (stack_a->size > 3)
    {
        i = stack_a->size - 1;
        if (i > 3 && get_distance(stack_a, i - 1) < get_distance(stack_a, i) - 1)
        {
            ft_strattach(&result, push_nbr_b(stack_a, stack_b, i - 1));
            ft_strattach(&result, push_nbr_b(stack_a, stack_b, i));
            ft_strattach(&result, exec_str(stack_a, stack_b, "sb\n"));
        }
        ft_strattach(&result, push_nbr_b(stack_a, stack_b, i));
    }
    ft_strattach(&result, solve_3stack(stack_a, stack_b)); 
    while (stack_b->size > 0)
    {
        ft_strattach(&result, exec_str(stack_a, stack_b, "pa\n"));
    }
    return (result);
}
