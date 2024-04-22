/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:38:18 by aandrieu          #+#    #+#             */
/*   Updated: 2023/08/31 11:38:21 by aandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_data *data)
{
	int	bit;
	int	i;
	int	temp;

	bit = 0;
	temp = data->size_a;
	while (1)
	{
		i = 0;
		while (i < temp)
		{
			if (((data->pile_a[0] >> bit) & 1) == 0)
				push_b(data);
			else
				rotate_a(data);
			i++;
		}
		fulled_a(data);
		bit++;
		if (is_sorted(data))
			break ;
	}
}

void	check_array_size(t_data *data)
{
	if (is_sorted(data) == 1)
		return ;
	else
	{
		if ((data->size_a) == 1)
			return ;
		else if ((data->size_a) == 2)
			sort2(data);
		else if ((data->size_a) == 3)
			sort3(data);
		else if ((data->size_a) == 4)
			sort4(data);
		else if ((data->size_a) <= 5)
			sort5(data);
		else if (data->size_a > 5 && data->size_a <= 100)
			radix_sort(data);
		else if (data->size_a > 100 && data->size_a <= 500)
			radix_sort(data);
	}
}

void	ft_free(int *temp, t_data *data, int argc, char **args)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	free(data->pile_a);
	free(data->pile_b);
	free(temp);
	free(data);
}

void	init_pile(int argc, char **argv, t_data *data, int *temp)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (is_digit(*argv[i]) != 0)
		{
			data->pile_a[i] = ft_atoi(data, temp, argv[i]);
			i++;
		}
		else
			ft_error_max(data, temp);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		*temp;
	char		**args;
	int		len;

	data = malloc((sizeof(t_data)) * 1);
	len = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[len])
			len++;
		check_errors(data, len + 1, args);
		ft_setup(data, len + 1);
		
		data->pile_a = malloc(sizeof(int) * (data->size_a));
		data->pile_b = malloc(sizeof(int) * (data->size_a));
		temp = malloc((sizeof(int)) * (data->size_a));
		init_pile(len + 1, args, data, temp);
	}
	else
	{
	check_errors(data, argc, argv);
	ft_setup(data, argc);
	data->pile_a = malloc(sizeof(int) * (data->size_a));
	data->pile_b = malloc(sizeof(int) * (data->size_a));
	temp = malloc((sizeof(int)) * (data->size_a));
	init_pile2(argc, argv, data, temp);
	}
	ft_check_double(temp, data);
	sort_to_temp(temp, data);
	temp_to_index(temp, data);
	check_array_size(data);
	ft_free(temp, data, argc, args);
	return (0);
}