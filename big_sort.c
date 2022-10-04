/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:18:04 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/04 11:18:06 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    midpoint_a(data *data)
{
	int	median;
	int cluster;
	
	//data->len_a = lst_len(data->head_a);
	cluster = 1;
	
	
	while (data->len_a > 5)
	{
		median = get_median(data->head_a, data->head_a->cluster);
		printf("median a: %d\n", median);
		while (data->len_a != 0)
    	{
        	if (data->head_a->numb < median)
            	pb(&data->head_b, &data->head_a);
        	else if (data->head_a->numb >= median)
			{
            	ra(&data->head_a);
			}
			data->len_a--;
    	}   
		lst_print(data->head_a, 'A', "in midpoint_a");
		lst_print(data->head_b, 'B', "in midpoint_a");
		data->len_a = lst_len(data->head_a);
		cluster++;
		set_cluster(data->head_a, cluster);
	}
	printf("len_a end: %d\n", data->len_a);
}

void midpoint_b(data *data)
{   
    int cluster;
    int counter;
    int len;

    while (lst_len(data->head_b) > 2)
    {
		//sort the group which has the same cluster and counter based on the top node off b 
		cluster = data->head_b->cluster;
		counter = data->head_b->counter;
		len = get_len_counter(data->head_b, cluster, counter);
		printf("len in midpoint_b: %d\n", len);
		printf("cluster in midpoint_b: %d\n", cluster);
		printf("counter in midpoint_b: %d\n", counter);
		
		if (len == 1)
			pa(&data->head_a, &data->head_b);
		else if (len == 2)
		{
			if (data->head_b->numb < data->head_b->next->numb)
				sb(data->head_b);
			pa(&data->head_a, &data->head_b);
			pa(&data->head_a, &data->head_b);
		}
		else
			{
				midpoint_sub_b(data, cluster, counter);
				lst_print(data->head_a, 'A', "after midpoint_b");
				lst_print(data->head_b, 'B', "after midpoint_b");
			}
	}
}

void	midpoint_sub_b(data *data, int cluster, int counter)
{
	int median;
    int len;


	median = get_median(data->head_b, cluster);
	printf("median b: %d\n", median);
	printf("cluster: %d\n", cluster);
	printf("counter: %d\n", counter);
	
    len = get_len_counter(data->head_b, cluster, counter);
	if(data->head_a->cluster == data->head_b->cluster)
		data->count++;
	else
		data->count = ++counter;
    printf("len cluster b: %d\n", len);
	while (len)
	{
		if (data->head_b->numb > median)
        {
            data->head_b->counter = data->count;
            pa(&data->head_a, &data->head_b);
        }
		else if (data->head_b->numb <= median)
		{
			rb(&data->head_b);
			data->rb_count++;
		}
        len--;
	}
	while (data->rb_count)
    {
        rrb(&data->head_b);
        data->rb_count--;
    }
    lst_print(data->head_a, 'A', "after midpoint__sub_b");
	lst_print(data->head_b, 'B', "after midpoint_sub_b");
    check_a(data, cluster, counter); //mind that the counter in the beginning is one less then the counter here, line 113
}

void check_a(data *data, int cluster, int counter)
{
    int len;
    while (is_cluster_a_sorted(data->head_a, cluster, counter) == 0) //mind that counter is +1 line 114.
    {
        len = get_len_counter(data->head_a, cluster, counter); 
        if (len <= 5)
        {
            pick_sort(len, data);
            lst_print(data->head_a, 'A', "after pick_sort check_a");
	        lst_print(data->head_b, 'B', "after pick_sort check_a");
        }
        else
        {
            midpoint_sub_a(data, cluster, counter);
            lst_print(data->head_a, 'A', "after midpoint_sub_a");
	        lst_print(data->head_b, 'B', "after midpoint_sub_a");
        }
    }
}

void midpoint_sub_a(data *data, int cluster, int counter)
{
	int median;
	int len;

	printf("cluster midpointalgo a: %d\n", cluster);
	median = get_median(data->head_a, cluster);
	printf("median b: %d\n", median);
	
	if(data->head_a->cluster == data->head_b->cluster)
		data->count++;
	else
		data->count = ++counter;
    len = get_len_counter(data->head_a, cluster, counter);
	while (len)
	{
		if (data->head_a->numb < median)
		{
			
		    	data->head_a->counter = data->count;
			pb(&data->head_b, &data->head_a);
		}	
		else if (data->head_a->numb >= median)
		{
			ra(&data->head_a);
			data->ra_count++;
		}
        len--;
	}
	while (data->ra_count)
	{
		rra(&data->head_a);
		data->ra_count--;
	}	
}

void	big_sort(data *data)
{
	lst_print(data->head_a, 'A', "begin big_sort");
	lst_print(data->head_b, 'B', "begin big sort");
	set_data(data, 1, 1);
	lst_print(data->head_a, 'A', "after setdata");
	lst_print(data->head_b, 'B', "after setdata");
	midpoint_a(data);
	lst_print(data->head_a, 'A', "after midpoint_a");
	lst_print(data->head_b, 'B', "after midpoint_a");
	//printf("len_a: %d\n", data->len_a);
	pick_sort(data->len_a, data);
	lst_print(data->head_a, 'A', "after picksort in big_sort");
	lst_print(data->head_b, 'B', "after picksort in big_sort");
	midpoint_b(data);
	if (data->head_b->numb < data->head_b->next->numb)
		sb(data->head_b);
	pa(&data->head_a, &data->head_b);
	pa(&data->head_a, &data->head_b);
	lst_print(data->head_a, 'A', "after midpoint_b");
	lst_print(data->head_b, 'B', "after midpoint_b");

}