/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:52:59 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/24 09:16:14 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_down_elem(t_node **head)
{
	t_node	*sec_last;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	sec_last = NULL;
	last = *head;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *head;
	*head = last;
	last = NULL;
}

/* shift down all elements by 1 of stack a. Last element becomes first */
void	rra(t_node **a)
{
	shift_down_elem(a);
	write(1, "rra\n", 4);
}

/* shift down all elements by 1 of stack b. Last element becomes first.*/
void	rrb(t_node **b)
{
	shift_down_elem(b);
	write(1, "rrb\n", 4);
}

/* execute rra() and rrb()*/
void	rrr(t_node **a, t_node **b)
{
	shift_down_elem(a);
	shift_down_elem(b);
	write(1, "rrr\n", 4);
}
