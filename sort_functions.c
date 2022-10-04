/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:36:26 by fiselann          #+#    #+#             */
/*   Updated: 2022/09/23 15:28:53 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_two_a(data *data)
{
	printf("sort two\n");
	if (is_a_sorted(data->head_a) == 1)
		return ;
	else
		sa(data->head_a);
}

void	sort_three_a(data *data)
{
	printf("sort_three\n");
	lst_print(data->head_a, 'A', "begin sort3");
	/*stack: 2 - 1 -3*/
	if (data->head_a->numb > data->head_a->next->numb && data->head_a->numb < data->head_a->next->next->numb)
		sa(data->head_a);
	/* stack: 2 - 3 - 1 */
	else if (data->head_a->numb < data->head_a->next->numb && data->head_a->numb >data->head_a->next->next->numb)
		rra(&data->head_a);
	/* stack: 3 - 1 - 2 */
	else if (data->head_a->numb > data->head_a->next->numb && data->head_a->numb > data->head_a->next->next->numb && data->head_a->next->numb < data->head_a->next->next->numb)
		ra(&data->head_a);
	/* stack: 3 - 2 - 1 */
	else if (data->head_a->numb > data->head_a->next->numb && data->head_a->numb > data->head_a->next->next->numb && data->head_a->next->numb > data->head_a->next->next->numb)
	{
		ra(&data->head_a);
		lst_print(data->head_a, 'A', "after ra()");
		sa(data->head_a);
		lst_print(data->head_a, 'A', "after sa()");
	}
	/* stack: 1 - 3 - 2 */
	else if (data->head_a->numb < data->head_a->next->numb && data->head_a->numb < data->head_a->next->next->numb && data->head_a->next->numb > data->head_a->next->next->numb)
	{

		sa(data->head_a);
		lst_print(data->head_a, 'A', "after sa()");
		ra(&data->head_a);
		lst_print(data->head_a, 'A', "after ra()");
	}
}

void	sort_four_five_a(data *data, int elements)
{
	size_t position;

	//lst_print(data->head_a, 'A', "begin sort five");
	//lst_print(data->head_b, 'B', "begin sort five");
	while(elements - 3)
	{
		pb(&data->head_b, &data->head_a);
		elements--;
	}
	//lst_print(data->head_a, 'A', "after pb() pb()");
	//lst_print(data->head_b, 'B', "after pb() pb()");
	sort_three_a(data);	
	//lst_print(data->head_a, 'A', "after sort three");
	//lst_print(data->head_b, 'B', "after sort three");
	while(data->head_b != NULL)
	{
		position = find_position_in_list(data->head_a, data->head_b->numb);
		sort_by_position(&data->head_a, &data->head_b, position);
		//lst_print(data->head_a, 'A', "after sort five");
		//lst_print(data->head_b, 'B', "after sort five");
	}
}

void	sort_by_position(list_ints **head_a, list_ints **head_b, size_t position)
{
	size_t count;
	size_t len;

	//lst_print(*head_a, 'a', "sort_by_position before");
	//lst_print(*head_b, 'b', "sort_by_position before");
	//printf("position: %u off numb: %d\n", position, (*head_b)->numb);
	len = lst_len(*head_a);
	//printf("len: %zu\n", len);
	/* upper half off the stack*/
	if (position <= (len / 2 + 1))
	{
		count = position;
		while (position)
		{
			ra(&(*head_a));
			position--;
			//lst_print(*head_a, 'A', "in loop");
		}
		pa(&(*head_a), &(*head_b));
		while(count)
		{
			rra(&(*head_a));
			count--;	
		}
	}
	/*lower half off the stack*/
	else if(position > (len / 2 + 1))
	{
		count = len - position + 1;
		printf("count in lower half: %zu\n", count);
		while ((len - position) > 0)
		{
			rra(&(*head_a));
			position++;
			//lst_print(*head_a, 'A', "in loop");
		}
		pa(&(*head_a), &(*head_b));
		while(count > 0)
		{
			ra(&(*head_a));
			count--;	
		}
	}
	//lst_print(*head_a, 'a', "sort_by_position after");
	//lst_print(*head_b, 'b', "sort_by_position after");
}

int	find_position_in_list(list_ints *head_a, int numb_to_find)
{
	unsigned int position;
	list_ints *temp;

	temp = head_a;
	position = 0;
	while(temp != NULL)
	{
		if (numb_to_find > temp->numb)
			position++;
		if (numb_to_find < temp->numb)
			break ;
		temp = temp->next;
	}
	return (position);
}

/* main to test these functions
 * > gcc -Wall -Wextra -Werror sort_functions.c sort_operations_1.c sort_operations_2.c sort_operations_3.c list_functions.c utils.c
 * > ./a.out
*/

/*int	main(void)
{
	list_ints n1, n2, n3, n4, n5;
	list_ints	*head_a;

	n1.numb = 3;
	n2.numb = 300;
	n3.numb = 100;
	n4.numb = 28;
	n5.numb = 5;

	head_a = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;
	

	head_a = sort_five(head_a);
	
	return (0);
}
*/