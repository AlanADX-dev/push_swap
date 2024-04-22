/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kro <kro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:37:21 by aandrieu          #+#    #+#             */
/*   Updated: 2023/09/04 15:22:18 by kro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if (c>= '0' && c <= '9' || c == ' ' || c == '-')
		return (1);
	else
		return (0);
}

int	ft_check_double(int *temp, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_a)
	{
		j = i + 1;
		while (j < data->size_a)
		{
			if (data->pile_a[i] == data->pile_a[j])
			{
				ft_printf("Error\n");
				free(data->pile_a);
				free(data->pile_b);
				free(temp);
				free(data);
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	error(t_data *data, char *str)
{
	ft_printf("%s", str);
	free(data);
	exit (0);
}

void	ft_error_max(t_data *data, int *temp)
{
	ft_printf("Error\n");
	free(data->pile_a);
	free(data->pile_b);
	free(temp);
	free(data);
	exit(0);
}

void	check_errors(t_data *data, int argc, char **argv)
{
	if (argc < 2)
		error(data, "");
}
