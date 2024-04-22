/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kro <kro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:38:35 by aandrieu          #+#    #+#             */
/*   Updated: 2023/09/04 15:22:22 by kro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>

typedef struct s_data
{
	int		*pile_a;
	int		*pile_b;
	int		size_a;
	int		size_b;
	int		len;
}t_data;

int		is_sorted(t_data *data);
int		main(int argc, char **argv);
int		ft_check_double(int *temp, t_data *data);
int		ft_atoi(t_data *data, int *temp, char *str);
int		is_digit(char c);


void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_s(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_r(t_data *data);
void	reverse_a(t_data *data);
void	reverse_b(t_data *data);
void	reverse_r(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	ft_setup(t_data *data, int argc);
void	sort_to_temp(int *temp, t_data *data);
void	temp_to_index(int *temp, t_data *data);
void	sort2(t_data *data);
void	sort3(t_data *data);
void	sort4(t_data *data);
void	sort5(t_data *data);
void	fulled_a(t_data *data);
void	radix_sort(t_data *data);
void	check_array_size(t_data *data);
void	check_errors(t_data *data, int argc, char **argv);
void	push_and_rotate(t_data *data);
void	ft_error_max(t_data *data, int *temp);
void	ft_free(int *temp, t_data *data, int argc, char **args);
void	init_pile2(int argc, char **argv, t_data *data, int *temp);



char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);



#endif
