/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:33:20 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/30 19:01:49 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	set_data(t_data *data, int cluster)
{
	set_cluster(data->a, cluster);
	data->len_a = lst_len(data->a);
	data->rb_count = 0;
	data->ra_count = 0;
}

void	set_cluster(t_node *head, int cluster)
{
	while (head != NULL)
	{
		head->cluster = cluster;
		head = head->next;
	}
}

int	is_a_sorted(t_node *a)
{
	t_node	*temp;
	int		len;

	temp = a;
	len = lst_len(a);
	while (len--)
	{
		if (temp->numb < temp->next->numb)
			temp = temp->next;
		else
			return (0);
		if (!temp->next)
			return (1);
	}
	return (1);
}

int	is_cluster_a_sorted(t_node *a, int cluster)
{
	if (a->next == NULL)
		return (1);
	while (a->cluster == cluster)
	{
		if (a->numb < a->next->numb)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int	is_cluster_b_sorted(t_node *b, int cluster)
{
	if (b->next == NULL || !b)
		return (1);
	while (b->cluster == cluster)
	{
		if (b->numb > b->next->numb)
			b = b->next;
		else
			return (0);
	}
	return (1);
}
