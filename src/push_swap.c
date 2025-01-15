/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:35:17 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/12/21 16:27:50 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

static int	get_argv_size(int argc, char **argv)
{
	int		size;
	char	**tmp_arr;

	if (argc == 2)
	{
		size = 1;
		tmp_arr = ft_split(argv[1], ' ');
		while (tmp_arr[size])
			size++;
		free_str_arr(tmp_arr);
	}
	else
		size = argc - 1;
	return (size);
}

static int	*init_arr(int argc, char **argv)
{
	char	**tmp_arr;
	int		i;
	int		size;
	int		*arr;

	if (argc == 2)
	{
		tmp_arr = ft_split(argv[1], ' ');
		size = get_argv_size(argc, argv);
	}
	else
	{
		tmp_arr = argv + 1;
		size = argc - 1;
	}
	arr = malloc(sizeof(int) * size);
	if (!arr)
		exit_err(NULL, NULL, 0);
	i = -1;
	while (tmp_arr[++i])
		arr[i] = ft_atoi(tmp_arr[i]);
	if (argc == 2)
		free_str_arr(tmp_arr);
	return (arr);
}

static void	sort_init(t_data *data)
{
	int	*tmp_arr;
	int	*new_arr;

	tmp_arr = bubble_sort(data, data->size);
	new_arr = replace(data, tmp_arr, data->size);
	free(data->arr);
	data->arr = new_arr;
	free(tmp_arr);
	if (is_full_sorted(data) || data->size == 1)
		return ;
	else if (data->size == 2)
		swap(data, 'a');
	else if (data->size == 3)
		sort_three(data);
	else if (data->size == 4)
		sort_four_and_five(data, 4);
	else if (data->size == 5)
		sort_four_and_five(data, 5);
	else
		radix_sort(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	data = malloc(sizeof(t_data));
	if (!data)
		exit_err(data, NULL, 0);
	data->arr = init_arr(argc, argv);
	data->size = get_argv_size(argc, argv);
	data->up = -1;
	data->down = 0;
	sort_init(data);
	return (free(data->arr), free(data), 0);
}
