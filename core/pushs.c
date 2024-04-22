/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:38:03 by aandrieu          #+#    #+#             */
/*   Updated: 2023/08/31 11:38:05 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data *data)
{
	int	i;

	i = 0;
	data->len = data->size_a;
	data->size_a += 1;
	data->size_b -= 1;
	while (data->len > 0)
	{
		data->pile_a[data->len] = data->pile_a[data->len -1];
		data->len--;
	}
	data->pile_a[0] = data->pile_b[0];
	while (i < data->size_b)
	{
		data->pile_b[i] = data->pile_b[i + 1];
		i++;
	}
	ft_printf("pa\n");
}

void	push_b(t_data *data)
{
	int	i;

	i = 0;
	data->len = data->size_b;
	data->size_b += 1;
	data->size_a -= 1;
	while (data->len > 0)
	{
		data->pile_b[data->len] = data->pile_b[data->len -1];
		data->len--;
	}
	data->pile_b[0] = data->pile_a[0];
	while (i < data->size_a)
	{
		data->pile_a[i] = data->pile_a[i + 1];
		i++;
	}
	ft_printf("pb\n");
}

void	fulled_a(t_data *data)
{
	while (data->size_b)
		push_a(data);
}

void	push_and_rotate(t_data *data)
{
	push_a(data);
	rotate_a(data);
}
