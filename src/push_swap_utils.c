/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:24:24 by hrother           #+#    #+#             */
/*   Updated: 2023/11/05 23:12:57 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *msg, t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->arr);
	free(stack_b->arr);
	ft_putendl_fd(msg, 2);
	exit(1);
}

char	*emptystr(void)
{
	char	*str;

	str = malloc(sizeof(char));
	str[0] = '\0';
	return (str);
}

t_stack	stackdup(t_stack stack)
{
	t_stack	dup;
	int		i;

	dup.max_size = stack.max_size;
	dup.size = stack.size;
	dup.arr = malloc(dup.max_size * sizeof(int));
	i = 0;
	while (i < dup.size)
	{
		dup.arr[i] = stack.arr[i];
		i++;
	}
	return (dup);
}

int	is_sorted(t_stack stack)
{
	int	i;
	int	result;

	if (stack.size != stack.max_size)
		return (0);
	i = 1;
	result = 1;
	while (i < stack.size)
	{
		result &= stack.arr[i - 1] >= stack.arr[i];
		i++;
	}
	return (result);
}

int	count_ops(char *str)
{
	int	res;

	if (!str)
		return (2147483647);
	res = 0;
	while (*str)
	{
		if (*str == '\n')
			res++;
		str++;
	}
	return (res);
}

int	init_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	char	**tmp;
	int		size;

	size = 0;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		while (tmp[size])
			size++;
		fill_stack(stack_a, tmp, size);
		while (size--)
			free(tmp[size]);
		free(tmp);
	}
	else
		fill_stack(stack_a, argv + 1, argc - 1);
	stack_b->max_size = stack_a->max_size;
	stack_b->size = 0;
	stack_b->arr = malloc(stack_b->max_size * sizeof(int));
	if (!(stack_a->arr && stack_b->arr))
		error("ERROR: Invalid Input", stack_a, stack_b);
	return (1);
}

char	*ft_strattach(char **str, char *to_attach, int repeats)
{
	char	*result;

	if (repeats < 1)
		return (*str);
	result = ft_strjoin(*str, to_attach);
	free(*str);
	*str = result;
	ft_strattach(str, to_attach, repeats - 1);
	return (*str);
}
