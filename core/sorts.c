/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:39:03 by aandrieu          #+#    #+#             */
/*   Updated: 2023/08/31 11:39:05 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if ((data->pile_a[i] > data->pile_a[i + 1]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	sort2(t_data *data)
{
	if (data->pile_a[0] > data->pile_a[1])
		swap_a(data);
}

void	sort3(t_data *data)
{
	int	i;

	i = 0;
	if (data->pile_a[i] > data->pile_a[i + 1]
		&& data->pile_a[i] < data->pile_a[i + 2])
		swap_a(data);
	else if (data->pile_a[i] > data->pile_a[i + 1]
		&& data->pile_a[i + 1] > data->pile_a[i + 2])
	{
		swap_a(data);
		reverse_a(data);
	}
	else if (data->pile_a[i] > data->pile_a[i + 2]
		&& data->pile_a[i + 2] > data->pile_a[i + 1])
		rotate_a(data);
	else if (data->pile_a[i] < data->pile_a[i + 2]
		&& data->pile_a[i + 2] < data->pile_a[i + 1])
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (data->pile_a[i] < data->pile_a[i + 1]
		&& data->pile_a[i] > data->pile_a[i + 2])
		reverse_a(data);
}

void	sort4(t_data *data)
{
	int	i;

	i = 0;
	if (data->pile_a[1] == 3)
		rotate_a(data);
	else if (data->pile_a[2] == 3)
	{
		reverse_a(data);
		reverse_a(data);
	}
	else if (data->pile_a[3] == 3)
		reverse_a(data);
	push_b(data);
	sort3(data);
	push_a(data);
	rotate_a(data);
}

void	sort5(t_data *data)
{
	if (data->pile_a[4] == 4)
		reverse_a(data);
	else if (data->pile_a[3] == 4)
	{
		reverse_a(data);
		reverse_a(data);
	}
	else
	{
		while (data->pile_a[0] != 4)
			rotate_a(data);
	}
	push_b(data);
	if (data->pile_a[3] == data->pile_b[0] - 1)
		reverse_a(data);
	else
	{
		while (data->pile_a[0] != 3)
			rotate_a(data);
	}
	push_b(data);
	sort3(data);
	push_and_rotate(data);
	push_and_rotate(data);
}
