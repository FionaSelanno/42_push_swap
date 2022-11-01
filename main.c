/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:40:36 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/01 10:27:46 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pick_sort(int elem_count, t_data *data)
{	
	if (is_a_sorted(data->a) == 1)
		return ;
	else if (elem_count == 1)
		return ;
	else if (elem_count == 2)
		sort_two_a(data);
	else if (elem_count == 3)
		sort_three_a(data);
	else if (elem_count == 4)
		sort_four_five_a(data, elem_count);
	else if (elem_count >= 5)
	{
		change_lstval(data->a);
		big_sort(data);
	}
}

void	big_sort(t_data *data)
{
	set_data(data, 1);
	midpoint_a(data);
	pick_sort(data->len_a, data);
	midpoint_b(data);
}

int	main(int argc, char **argv)
{
	int			el;
	t_node		*a;
	t_data		data;

	a = NULL;
	el = 0;
	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		el = handle_one_arg(argv[1], &a);
		if (el == 0)
			return (0);
		if (el == 1 || is_a_sorted(a) == 1)
			ft_exit(&a, NULL, 0);
	}
	else if (argc > 2)
		el = create_lst(argc, argv, &a);
	data_init(&data, &a);
	pick_sort(el, &data);
	free_lst(&a);
	return (0);
}
