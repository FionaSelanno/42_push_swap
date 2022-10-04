/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:22:39 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/04 11:01:32 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
#include "unistd.h"

//TODO: figure out if I have to pass in head to freen all items before exiting the program.
//TODO: undo using printf to write the "error"
void	ft_exit(int error_numb)
{
	//lst_freeall(&head);
	//write(1, "Error\n", 6);
	/* 
		error 1: no number input
		error 2: number input is not within integers limits
		error 3: duplicates in input
		error 4: memory allocation failed
	*/
	printf("Error: %d\n", error_numb);
	exit(0);
	return ;
}

void ft_swap_numb(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void	data_init(data *data, list_ints **head_a)
{
	//printf("crash\n");
	data->head_a = *head_a;
	//printf("crash\n");
	data->head_b = NULL;
	data->len_a = 0;
	data->rb_count = 0;
	data->ra_count = 0;
	
}

int	get_median(list_ints *head, int cluster)
{
	size_t sum;
	int		len;
	
	sum = 0;
	len = 0;
	//printf("head->cluster: %d, cluster: %d\n", head->cluster, cluster);
	while (head)
	{
		if (head->cluster != cluster)
			break ;
		sum += head->numb;
		len++;
		head = head->next;
	}
	printf("len: %d\n", len);
	printf("sum: %ld\n", sum);
	return ((int)(sum / len));
}

void set_data(data *data, int cluster, int counter)
{
	set_cluster(data->head_a, cluster);
	set_counter(data->head_a, cluster, counter);
    data->len_a = lst_len(data->head_a);
	data->rb_count = 0;
	data->ra_count = 0;

}

void	set_cluster(list_ints *head, int cluster)
{
	while(head != NULL)
	{
		head->cluster = cluster;
		head = head->next;
	}
}

void	set_counter(list_ints *head, int cluster, int counter)
{
	while(head != NULL && head->cluster == cluster)
	{
		head->counter = counter;
		head = head->next;
	}
}

int is_a_sorted(list_ints *head_a)
{
	if (head_a->next == NULL)
		return (1);
	while(head_a)
	{
		//printf("loop\n");
		if (head_a->numb < head_a->next->numb)
			head_a = head_a->next;
		else
		{
			//printf("a is not sorted\n");
			return (0);
		}
		if (!head_a->next)
			return (1);
	}
	return(1);
}

int	is_cluster_a_sorted(list_ints *head_a, int cluster, int counter)
{
	if (head_a->next == NULL)
		return (1);
	while (head_a->cluster == cluster && head_a->counter == counter)
	{
		if(head_a->numb < head_a->next->numb)
			head_a = head_a->next;
		else
		{
			printf("cluster: %d, counter: %d in A is not sorted\n", cluster, counter);
			return (0);
		}
	}
	printf("cluster: %d, counter: %d in A is sorted\n", cluster, counter);
	return (1);
}

int	is_cluster_b_sorted(list_ints *head_b, int cluster, int counter)
{
	if (head_b->next == NULL || head_b)
		return (1);
	while (head_b->cluster == cluster && head_b->counter == counter)
	{
		if(head_b->numb > head_b->next->numb)
			head_b = head_b->next;
		else
		{
			printf("cluster: %d, counter:%d in B is not sorted\n", cluster, counter);
			return (0);
		}
	}
	printf("cluster: %d, counter: %d in B is sorted\n", cluster, counter);
	return (1);
}

int	get_len_counter(list_ints *head, int cluster, int counter)
{
	int	len;

	len = 0;
	while (head != NULL && head->cluster == cluster && head->counter == counter)
	{
		len++;
		head = head->next;
	}
	return (len);
}

int get_len_cluster(list_ints *head, int cluster)
{
	int len;
	
	len = 0;
	while (head != NULL && head->cluster == cluster)
	{
		len++;
		head = head->next;
	}
	return (len);
}

void	sort_b(data *data, int cluster, int counter)
{
	int len;
	
	len = get_len_counter(data->head_b, cluster, counter);
	printf("sort_b, len: %d\n", len);
	while(len)
	{
		pa(&data->head_a, &data->head_b);
		len--;
	}
}