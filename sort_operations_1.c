/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:32:02 by fiselann          #+#    #+#             */
/*   Updated: 2022/05/26 12:35:32 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* swap first 2 ints off stack a */
void	sa(list_ints *head_a)
{
	//printf("in sa\n");
	if (!head_a || !head_a->next)
		return ;
	ft_swap_numb(&head_a->numb, &head_a->next->numb);
	write(1, "sa\n", 3);
}

/* swap first 2 ints off stack b */
void	sb(list_ints *head_b)
{
	if (!head_b || !head_b->next)
		return ;
	ft_swap_numb(&head_b->numb, &head_b->next->numb);
	write(1, "sb\n", 3);
}

/* execute sa and sb */
void	ss(list_ints *head_a, list_ints *head_b)
{
	sa(head_a);
	sb(head_b);
	write(1, "ss\n", 3);
}

 /*put first element off stack b and put it on top off stack a*/
void	pa(list_ints **head_a, list_ints **head_b)
{
	list_ints	*head_temp;

	if (*head_b == NULL)
		return ;
	else
	{
		head_temp = *head_b;
		*head_b = head_temp->next;
		head_temp->next = *head_a;
		*head_a = head_temp;
	}
	write(1, "pa\n", 3);
}

 /*put first element off stack a and put it on top off stack b*/
void	pb(list_ints **head_b, list_ints **head_a)
{
	list_ints	*head_temp;

	if (*head_a == NULL)
		return ;
	else
	{
		head_temp = *head_a;
		*head_a = head_temp->next;
		head_temp->next = *head_b;
		*head_b = head_temp;
	}
	write(1, "pb\n", 3);
}

/* uncomment main to do small tests on these functions 
 * > gcc -Wall -Wextra -Werror sort_operations_1.c utils.c list_functions.c
 * > ./a.out
*/
/*int	main(void)
{
	
	list_ints n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
	list_ints	*head_a;
	list_ints	*head_b;

	n1.index = n2.index = n3.index = n4.index = n5.index = n6.index = n7.index = n8.index = n9.index = n10.index = 0;

	n1.numb = 2;
	n2.numb = 1;
	n3.numb = 3;
	n4.numb = 6;
	n5.numb = 5;
	n6.numb = 8;
	n7.numb = 30;
	n8.numb = 15;
	n9.numb = 4;
	n10.numb = 18;

	head_a = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = NULL;

	head_b=&n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = &n10;
	n10.next = NULL;

	lst_print(head_a, 'A', "LIST A");
	lst_print(head_b, 'B', "LIST B");
	sa(head_a);
	lst_print(head_a, 'A', "LIST A after sa()");
	sb(head_b);
	lst_print(head_b, 'B', "LIST B after sb()");
	pa(&head_a, &head_b);
	lst_print(head_a, 'A', "LIST A after pa()");
	lst_print(head_b, 'B', "LIST B after pa()");
	pb(&head_b, &head_a);
	lst_print(head_a, 'A', "LIST A after pb()");
	lst_print(head_b, 'B', "LIST B after pb()");
	
	return (0);
} */