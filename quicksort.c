/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 01:48:50 by hrother           #+#    #+#             */
/*   Updated: 2023/10/23 16:47:08 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *arr, int start, int end)
{
	int	i_right;
	int	i_left;

	i_left = 0;
	i_right = 1;
	while (i_left < i_right)
	{
		i_left = start;
		i_right = end - 1;
		while (arr[i_left] > arr[end])
			i_left++;
		while (arr[i_right] < arr[end])
			i_right--;
		if (i_left < i_right)
			swap_ab(arr + i_left, &arr[i_right]);
	}
	swap_ab(&arr[i_left], &arr[end]);
	return (i_left);
}

void	quick_sort(int *arr, int start, int end)
{
	int	division;
	int	i = start;

	if (start >= end)
		return ;
	division = partition(arr, start, end);
	while (i <= end)
	{
		//ft_printf("%d, ", arr[i]);
		i++;
	}
	//ft_printf("\b\b\n");
	quick_sort(arr, start, division - 1);
	quick_sort(arr, division + 1, end);
}
