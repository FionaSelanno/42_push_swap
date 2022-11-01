/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:32:02 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/30 16:17:24 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap first 2 ints off stack a */
void	sa(t_node *a)
{
	if (!a || !a->next)
		return ;
	ft_swap_numb(&a->numb, &a->next->numb);
	write(1, "sa\n", 3);
}

/* swap first 2 ints off stack b */
void	sb(t_node *b)
{
	if (!b || !b->next)
		return ;
	ft_swap_numb(&b->numb, &b->next->numb);
	write(1, "sb\n", 3);
}

/* execute sa and sb 
void	ss(t_node *a, t_node *b)
{
	if (!b || !b->next || !a || !a->next)
		return ;
	ft_swap_numb(&a->numb, &a->next->numb);
	ft_swap_numb(&b->numb, &b->next->numb);
	write(1, "ss\n", 3);
} */

/*put first element off stack b and put it on top off stack a*/
void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*b == NULL)
		return ;
	else
	{
		temp = *b;
		*b = temp->next;
		temp->next = *a;
		*a = temp;
	}
	write(1, "pa\n", 3);
}

/*put first element off stack a and put it on top off stack b*/
void	pb(t_node **b, t_node **a)
{
	t_node	*temp;

	if (*a == NULL)
		return ;
	else
	{
		temp = *a;
		*a = temp->next;
		temp->next = *b;
		*b = temp;
	}
	write(1, "pb\n", 3);
}
