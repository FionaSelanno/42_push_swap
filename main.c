/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:40:36 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/27 15:14:55 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

/*TO DO: figure out manually sort 5 nodes not effecien enough */
void	pick_sort(int elem_count, t_data *data)
{	
	//printf("in picksort\n");
	if (is_a_sorted(data->a) == 1)
		return ;
	else if (elem_count == 1)
		return ;
	else if (elem_count == 2)
		sort_two_a(data);
	else if (elem_count == 3)
		sort_three_a(data);
	else if (elem_count == 4 || elem_count == 5)
		sort_four_five_a(data, elem_count);
	else if (elem_count >= 6)
	{
		change_lstval(data->a);
		//lst_print(data->a, 'A', "after changeval");
		//printf("listlen after: %zu\n", lst_len(data->a));
		big_sort(data);
	}
	//(data->a, 'A', "after picksort");
	//lst_print(data->b, 'B', "after picksort");
}

void	big_sort(t_data *data)
{
	set_data(data, 1);
	midpoint_a(data);
	//printf("lst_len: %zu\n", lst_len(data->a));
	pick_sort(data->len_a, data);
	midpoint_b(data);
}

int	main(int argc, char **argv)
{
	int			elements;
	t_node		*a;
	t_data		data;

	(void)data;
	a = NULL;
	elements = 0;
	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		elements = handle_one_arg(argv[1], &a);
		if (elements == 1)
			return (0);
		if (elements == 0)
			ft_exit(0, &a, NULL);
	}
	else if (argc > 2)
		elements = create_lst(argc, argv, &a);
	//lst_print(a, 'A', "after putting everything in a list");
	//printf("listlen af first: %zu\n", lst_len(a));
	data_init(&data, &a);
	pick_sort(elements, &data);
	//lst_print(data.a, 'A', "after pick_sort in main");
	//lst_print(data.b, 'B', "after pick_sort in main");
	//printf("listlen after picksort: %zu\n", lst_len(a));
	is_a_sorted(a);
	return (0);
}
