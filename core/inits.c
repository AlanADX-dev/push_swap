/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kro <kro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:37:43 by aandrieu          #+#    #+#             */
/*   Updated: 2023/09/04 15:22:20 by kro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_setup(t_data *data, int argc)
{
	data->size_a = argc -1;
	data->size_b = 0;
}

void	sort_to_temp2(int *temp, t_data *data, int *temp_pile_a)
{
	int	temp_value;
	int	i;
	int	j;
	int	min_index;

	i = 0;
	while (i < data->size_a)
	{
		min_index = i;
		j = i + 1;
		while (j < data->size_a)
		{
			if (temp_pile_a[j] < temp_pile_a[min_index])
				min_index = j;
			j++;
		}
		temp_value = temp_pile_a[i];
		temp[i] = temp_pile_a[min_index];
		temp_pile_a[min_index] = temp_value;
		i++;
	}
}

void	sort_to_temp(int *temp, t_data *data)
{
	int	*temp_pile_a;
	int	i;

	temp_pile_a = malloc(sizeof(int) * data->size_a);
	i = 0;
	while (i < data->size_a)
	{
		temp_pile_a[i] = data->pile_a[i];
		i++;
	}
	sort_to_temp2(temp, data, temp_pile_a);
	free(temp_pile_a);
}

void	temp_to_index(int *temp, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_a)
	{
		j = 0;
		while (data->pile_a[i] != temp[j])
		{
			j++;
		}
		data->pile_a[i] = j;
		i++;
	}
}

int	ft_atoi(t_data *data, int *temp, char *str)
{
	long int	res;
	int			sign;

	sign = 1;
	res = 0;
	if (*str == '\0')
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	res *= sign;
	if (res < -2147483648 || res > 2147483647)
		ft_error_max(data, temp);
	return (res);
}
