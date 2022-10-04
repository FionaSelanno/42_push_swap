/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:50:16 by fiselann          #+#    #+#             */
/*   Updated: 2022/09/20 12:07:45 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

/*shift up all elements of stack a by 1, first element becomes last one*/
void	ra(list_ints **head_a)
{
	list_ints	*last;
	list_ints *second;
	list_ints *sec_last;
	
	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	second = (*head_a)->next;
	sec_last = *head_a;
	while (sec_last->next != NULL)
		sec_last = sec_last->next;
	last = sec_last;
	last->next = *head_a;
	last->next->next = NULL;
	*head_a = second;
	sec_last = NULL;
	write(1, "ra\n", 3);
}

/*shift up all elements of stack b by 1, first element becomes last one*/
void	rb(list_ints **head_b)
{
	list_ints	*last;
	list_ints *second;
	list_ints *sec_last;
	
	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	second = (*head_b)->next;
	sec_last = *head_b;
	while (sec_last->next != NULL)
		sec_last = sec_last->next;
	last = sec_last;
	last->next = *head_b;
	last->next->next = NULL;
	*head_b = second;
	sec_last = NULL;
	write(1, "rb\n", 3);
}

/*do ra() and rb() at the same time*/
void	rr(list_ints **head_a, list_ints **head_b)
{
	ra(*&head_a);
	rb(*&head_b);
	write(1, "rr\n", 3);
}

/**** uncomment main to do small tests on the operations ****/
/*int	main(void)
{

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
	lst_print(head_a, 'A', "begin");
	ra(&head_a);
	lst_print(head_a, 'A', "after ra()");
	
	lst_print(head_b, 'B', "begin");
	rb(&head_b);
	lst_print(head_b, 'B', "after rb()");
	
	rr(&head_a, &head_b);
	lst_print(head_a, 'A', "after rr()");
	lst_print(head_b, 'B', "after rr()");
	return (0);
}*/
