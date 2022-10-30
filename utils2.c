/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:33:20 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/27 11:55:28 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	t_node *temp;

	temp = a;
	if (temp->next == NULL)
	{
		//printf("only one node, cluster a is sorted\n");
		return (1);
	}
	while (temp)
	{
		if (temp->numb < temp->next->numb)
			temp = temp->next;
		else
		{
			//printf("cluster a is not sorted\n");
			printf("node not sorted: %d\n", temp->numb);
			//lst_print(a, 'A', "in is_a_sorted");
			return (0);
		}
		if (!temp->next)
		{
			printf("cluster a is sorted\n");
			return (1);
		}
	}
	//printf("cluster a is sorted\n");
	return (1);
}

int	is_cluster_a_sorted(t_node *a, int cluster)
{

	//printf("cluster is a sorted: %d\n", cluster);
	//printf("counter is a sorted: %d\n", counter);
	if (a->next == NULL)
	{
		//printf("a node: %d, cluster: %d, counter: %d\n", a->numb, cluster, counter);
		return (1);
	}

	//printf("len: %d\n", len);
	while (a->cluster == cluster)
	{
		//printf("a node: %d, cluster: %d, counter: %d\n", a->numb, cluster, counter);
		if (a->numb < a->next->numb)
			a = a->next;
		else
		{
			//printf("cluster a is not sorted\n");
			return (0);
		}
	}
	//printf("cluster a is sorted\n");
	return (1);
}

int	is_cluster_b_sorted(t_node *b, int cluster)
{
	//printf("here\n");
	if (b->next == NULL || !b)
		return (1);
	while (b->cluster == cluster)
	{
		
		if (b->numb > b->next->numb)
			b = b->next;
		else
		{
			//printf("cluster a is not sorted\n");
			return (0);
		}
	}
	return (1);
}
