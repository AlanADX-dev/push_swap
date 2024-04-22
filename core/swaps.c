/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:39:15 by aandrieu          #+#    #+#             */
/*   Updated: 2023/08/31 11:39:16 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	int	temp;

	temp = data->pile_a[0];
	data->pile_a[0] = data->pile_a[1];
	data->pile_a[1] = temp;
	ft_printf("sa\n");
}

void	swap_b(t_data *data)
{
	int	temp;

	temp = data->pile_b[0];
	data->pile_b[0] = data->pile_b[1];
	data->pile_b[1] = temp;
	ft_printf("sb\n");
}

void	swap_s(t_data *data)
{
	swap_a(data);
	swap_b(data);
}
