/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:18:54 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/12/22 11:54:53 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

static int	has_repeated(int n, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == n)
			return (1);
		i++;
	}
	return (0);
}

static int	is_num(char *n)
{
	int	i;

	i = 0;
	if (n[0] == '-')
		i++;
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	total;
	int		sign;

	sign = 1;
	total = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = 44 - *str;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		total *= 10;
		total += *str - '0';
		str++;
	}
	return (sign * total);
}

void	check_args(int ac, char **av)
{
	char	**arr;
	long	num;
	int		i;

	i = 0;
	if (ac == 2)
		arr = ft_split(av[1], ' ');
	else
		arr = av + 1;
	while (arr[i])
	{
		if (!is_num(arr[i]))
			exit_err(NULL, arr, ac == 2);
		num = ft_atol(arr[i]);
		if (has_repeated(num, arr, i))
			exit_err(NULL, arr, ac == 2);
		if (num < INT_MIN || num > INT_MAX)
			exit_err(NULL, arr, ac == 2);
		i++;
	}
	if (ac == 2)
		free_str_arr(arr);
}
