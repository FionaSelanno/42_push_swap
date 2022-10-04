/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:40:36 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/04 09:09:49 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

/*
 *situation 1: if stack a contains 0 or 1 element:
 	-> there is no need to sort anything
 *situation 2: if stack contains 2 element then there are 2 possibilities:
 	-> the stack is already sorted
 	-> the stack is not sorted, you have to swap them.
 *situation 3: if stack a contains 3 elements:
 	-> write out all the possible posibilities, there should be 5, with a max off 3 steps
 *situation 4: if stack a contains 5 elements
 	-> push first 2 elements to stack b. Sort rest of stack a with situation 3 and push stack b back to stack a
 *situation 5: everything more then 6 elements.3.
 * TO DO: What about if the stack has 4 elements??
*/

void	pick_sort(int elem_count, data *data)
{	
	printf("elem_count: %d\n", elem_count);
	if (is_a_sorted(data->head_a) == 1)
		return ;
	else if (elem_count == 1)
		return ;
	else if (elem_count == 2)
	{
		sort_two_a(data);
	}
	else if (elem_count == 3)
	{
		sort_three_a(data);
	}	
	else if (elem_count == 4 || elem_count	== 5)
	{
		sort_four_five_a(data, elem_count);
	}	
	else if(elem_count >= 6)
	{
		big_sort(data);
	}	
}

int	main(int argc, char **argv)
{
	int	elements;
	int	numb;
	list_ints	*head_a;
	list_ints	*tail_a;
	list_ints	*new_item;
	data	data;
	
	//TODO: only declare data *data and int elements. The rest can be stored in data. But rewrite the first par.
	head_a = NULL;
	tail_a = NULL;
	//data = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		//if there is only one number input there is no need to sort, but you still have to check if the input is valid. If not it should display "Error"
		ft_atoi(argv[1]);
		return (0);
	}
	else if (argc > 2)
	{
		elements = 1;
		while(elements < argc)
		{
			numb = ft_atoi(argv[elements]);
			new_item = lst_new_item(numb, 0);
			if (!head_a)
			{
				head_a = new_item;
				tail_a = head_a;
			}
			tail_a = lst_addback(tail_a, new_item);
			elements++;
		}
		elements -= 1;
		if (!check_if_duplicates(head_a))
		{
			printf("in picksort\n");
			data_init(&data, &head_a);
			pick_sort(elements, &data);
			lst_print(data.head_a, 'A', "after pick_sort in main");
			lst_print(data.head_b, 'B', "after pick_sort in main");
		}
	//lst_print(head_a);	
	}
	return(0);
}