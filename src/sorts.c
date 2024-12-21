/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:35:44 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/12/21 16:28:02 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static int	get_max_bits(t_data *data)
{
	int	*tmp_arr;
	int	max;
	int	max_bits;
	int	i;

	i = 0;
	tmp_arr = data->arr;
	max = tmp_arr[0];
	max_bits = 0;
	while (i < data->size)
	{
		if (tmp_arr[i] > max)
			max = tmp_arr[i];
		i++;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	*replace(t_data *data, int *arr_sorted, int size)
{
	int	*new_arr;
	int	i;
	int	n;
	int	j;

	n = 0;
	i = 0;
	new_arr = malloc(sizeof(int) * size);
	if (!new_arr)
		exit_err(data, NULL, 0);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (data->arr[i] == arr_sorted[j])
			{
				new_arr[n] = j;
				n++;
			}
			j++;
		}
		i++;
	}
	return (new_arr);
}

int	*bubble_sort(t_data *data, int size)
{
	int	i;
	int	tmp_val;
	int	*tmp_arr;

	tmp_arr = malloc(sizeof(int) * size);
	if (!tmp_arr)
		exit_err(data, NULL, 0);
	ft_memcpy(tmp_arr, data->arr, sizeof(int) * size);
	i = 0;
	while (i < size - 1)
	{
		if (tmp_arr[i] > tmp_arr[i + 1])
		{
			tmp_val = tmp_arr[i];
			tmp_arr[i] = tmp_arr[i + 1];
			tmp_arr[i + 1] = tmp_val;
			i = 0;
		}
		else
			i++;
	}
	return (tmp_arr);
}

void	radix_sort(t_data *data)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = get_max_bits(data);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < data->size)
		{
			if ((data->arr[data->down] >> i) & 1)
				rotate(data, 'a');
			else
				push(data, 'b');
			j++;
		}
		while (stack_len(data, 'b') > 0)
			push(data, 'a');
		i++;
	}
}
