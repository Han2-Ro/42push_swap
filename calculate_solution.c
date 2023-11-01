/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:51:11 by hannes            #+#    #+#             */
/*   Updated: 2023/11/01 21:15:13 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	index_to_insert(t_stack *stack, int val)
{
	int	i;

	i = 0;
	while (stack->arr[i] > val)
		i++;
	while (stack->arr[i] < val)
		i++;
	return (i - 1);
}

int	n_ops_to_pb(t_stack *stack_a, t_stack *stack_b, int i_a)
{
	int	i_b;
	int	result;

	i_b = index_to_insert(stack_b, stack_a->arr[i_a]);
	if (i_a < stack_a->size / 2)
		result = i_a;
	else
		result = stack_a->size - i_a;
}

char	*calculate_solution(t_stack *stack_a, t_stack *stack_b)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char));
	result[0] = '\0';
	while (stack_a->size > 3)
	{
		
	}
	ft_strattach(&result, solve_3stack(stack_a, stack_b)); 
	while (stack_b->size > 0)
	{
		ft_strattach(&result, exec_str(stack_a, stack_b, "pa\n"));
	}
	return (result);
}
