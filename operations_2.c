/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:50:16 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/30 17:05:59 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_up_elem(t_node **head)
{
	t_node	*last;
	t_node	*second;
	t_node	*sec_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	second = (*head)->next;
	sec_last = *head;
	while (sec_last->next != NULL)
		sec_last = sec_last->next;
	last = sec_last;
	last->next = *head;
	last->next->next = NULL;
	*head = second;
	sec_last = NULL;
}

/*shift up all elements of stack a by 1, first element becomes last one*/
void	ra(t_node **a)
{
	shift_up_elem(a);
	write(1, "ra\n", 3);
}

/*shift up all elements of stack b by 1, first element becomes last one*/
void	rb(t_node **b)
{
	shift_up_elem(b);
	write(1, "rb\n", 3);
}

/*do ra() and rb() at the same time
void	rr(t_node **a, t_node **b)
{
	shift_up_elem(a);
	shift_up_elem(b);
	write(1, "rr\n", 3);
}
*/