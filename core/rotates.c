/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:38:55 by aandrieu          #+#    #+#             */
/*   Updated: 2023/08/31 11:38:56 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	int	temp;
	int	i;

	if (data->size_a <= 1)
		return ;
	temp = data->pile_a[0];
	i = 0;
	while (i < data->size_a - 1)
	{
		data->pile_a[i] = data->pile_a[i + 1];
		i++;
	}
	data->pile_a[data->size_a - 1] = temp;
	ft_printf("ra\n");
}

void	rotate_b(t_data *data)
{
	int	temp;
	int	i;

	if (data->size_b <= 1)
		return ;
	temp = data->pile_b[0];
	i = 0;
	while (i < data->size_b - 1)
	{
		data->pile_b[i] = data->pile_b[i + 1];
		i++;
	}
	data->pile_b[data->size_b - 1] = temp;
	ft_printf("rb\n");
}

void	rotate_r(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
}
