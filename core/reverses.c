/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverses.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:38:45 by aandrieu          #+#    #+#             */
/*   Updated: 2023/08/31 11:38:47 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_data *data)
{
	int	temp;
	int	i;

	if (data->size_a <= 1)
		return ;
	temp = data->pile_a[data->size_a - 1];
	i = data->size_a - 1;
	while (i > 0)
	{
		data->pile_a[i] = data->pile_a[i - 1];
		i--;
	}
	data->pile_a[0] = temp;
	ft_printf("rra\n");
}

void	reverse_b(t_data *data)
{
	int	temp;
	int	i;

	if (data->size_b <= 1)
		return ;
	temp = data->pile_b[data->size_b - 1];
	i = data->size_b - 1;
	while (i > 0)
	{
		data->pile_b[i] = data->pile_b[i - 1];
		i--;
	}
	data->pile_b[0] = temp;
	ft_printf("rrb\n");
}

void	reverse_r(t_data *data)
{
	reverse_a(data);
	reverse_b(data);
}
