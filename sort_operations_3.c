/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:52:59 by fiselann          #+#    #+#             */
/*   Updated: 2022/09/20 10:15:18 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* shift down all elements by 1 of stack a. Last element becomes first */
void	rra(list_ints **head_a)
{
	list_ints	*sec_last;
	list_ints	*last;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	sec_last = NULL;
	last = *head_a;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *head_a;
	*head_a = last;
	last = NULL;
	write(1, "rra\n", 4);
}

/* shift down all elements by 1 of stack b. Last element becomes first.*/
void	rrb(list_ints **head_b)
{
	list_ints	*sec_last;
	list_ints	*last;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	sec_last = NULL;
	last = *head_b;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *head_b;
	*head_b = last;
	last = NULL;
	write(1, "rrb\n", 4);
}

/* execute rra() and rrb()*/
void 	rrr(list_ints **head_a, list_ints **head_b)
{
	rra(*&head_a);
	rrb(*&head_b);
	write(1, "rrr\n", 4);
}

/**** uncomment main to do small tests on the operations ****/
/* RUN: gcc -Wall -Wextra -Werror sort_operations_3.c list_functions.c utils.c */
/*int	main(void)
{
	printf("test\n");

	list_ints	*new_node;
	list_ints	*head_a;
	list_ints	*head_b;
	int			numb;

	numb = 0;
	head_a = NULL;
	while(numb < 7)
	{
		new_node = lst_new_item(numb, 0);
		lst_addfront(&head_a, new_node);
		numb++;
	}

	numb = 10;
	head_b = NULL;
	while(numb < 15)
	{
		new_node = lst_new_item(numb, 0);
		lst_addfront(&head_b, new_node);
		numb++;
	}
	lst_print(head_a, 'A', "LIST A:\n");
	rra(&head_a);
	lst_print(head_a, 'A', "LIST A after rra():\n");

	lst_print(head_b, 'B', "LIST B:\n");
	rrb(&head_b);
	lst_print(head_b, 'B', "LIST B after rrb():\n");

	rrr(&head_a, &head_b);
	lst_print(head_a, 'A', "LIST A after rrr():\n");
	lst_print(head_b, 'B', "LIST B after rrr():\n");
	
	return (0);
}*/
