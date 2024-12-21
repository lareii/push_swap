/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:33:38 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/12/21 14:33:39 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	find_min_and_index(t_data *data, int *min, int *min_index)
{
	int	i;

	i = 0;
	*min = INT_MAX;
	while (i < data->size - data->down)
	{
		if (data->arr[i + data->down] < *min)
		{
			*min = data->arr[i + data->down];
			*min_index = i;
		}
		i++;
	}
}

static void	move_min_to_b(t_data *data, int min_index, int size)
{
	if (min_index == 1)
		swap(data, 'a');
	else if (min_index == 2)
	{
		rotate(data, 'a');
		swap(data, 'a');
	}
	else if (min_index == 3 && size == 4)
		reverse_rotate(data, 'a');
	else if (min_index == 3 && size == 5)
	{
		reverse_rotate(data, 'a');
		reverse_rotate(data, 'a');
	}
	else if (min_index == 4)
		reverse_rotate(data, 'a');
	if (!is_sorted(data, 'a'))
		push(data, 'b');
}

void	sort_three(t_data *data)
{
	if (data->arr[data->down] > data->arr[data->down + 1]
		&& data->arr[data->down] < data->arr[data->down + 2])
		swap(data, 'a');
	else if (data->arr[data->down] > data->arr[data->down + 1]
		&& data->arr[data->down] > data->arr[data->down + 2]
		&& data->arr[data->down + 1] < data->arr[data->down + 2])
		rotate(data, 'a');
	else if (data->arr[data->down] > data->arr[data->down + 1]
		&& data->arr[data->down] > data->arr[data->down + 2]
		&& data->arr[data->down + 1] > data->arr[data->down + 2])
	{
		rotate(data, 'a');
		swap(data, 'a');
	}
	else if (data->arr[data->down] < data->arr[data->down + 1]
		&& data->arr[data->down] > data->arr[data->down + 2])
		reverse_rotate(data, 'a');
	else if (data->arr[data->down] < data->arr[data->down + 1]
		&& data->arr[data->down] < data->arr[data->down + 2]
		&& data->arr[data->down + 1] > data->arr[data->down + 2])
	{
		reverse_rotate(data, 'a');
		swap(data, 'a');
	}
}

void	sort_four_and_five(t_data *data, int size)
{
	int	min;
	int	min_index;

	if (size == 4)
	{
		find_min_and_index(data, &min, &min_index);
		move_min_to_b(data, min_index, 4);
		sort_three(data);
		if (stack_len(data, 'b'))
			push(data, 'a');
	}
	if (size == 5)
	{
		find_min_and_index(data, &min, &min_index);
		move_min_to_b(data, min_index, 5);
		find_min_and_index(data, &min, &min_index);
		move_min_to_b(data, min_index, 4);
		sort_three(data);
		while (stack_len(data, 'b'))
			push(data, 'a');
	}
}
