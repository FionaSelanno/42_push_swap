/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:02:21 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/27 16:05:21 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	lst_len(t_node *head)
{
	t_node	*temp;
	int		len;

	temp = head;
	len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

t_node	*lst_tail(t_node *head)
{
	t_node	*temp_head;

	temp_head = head;
	while (temp_head)
	{
		if (!temp_head->next)
			return (temp_head);
		temp_head = temp_head->next;
	}
	return (temp_head);
}