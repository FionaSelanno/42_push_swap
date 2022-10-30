/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:16:11 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/27 16:21:28 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void	midpoint_a(t_data *data)
{
	int	median;
	int		top;
	int		bottom;
	t_node 	*temp;
	t_node	*tail;

	temp = data->a;
	tail = lst_tail(data->a);
	while (data->len_a > 4)
	{
		data->counter++;
		median = get_median(data->a, data->a->cluster);
		while (temp != tail)
		{      
			top = ix_first_top(temp, median);
			bottom = (data->len_a - ix_first_bottom(temp, median));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
			if (top <= bottom)
        		temp = best_move(data, top, bottom);
			else if (top > bottom)
				tail = best_move(data, top, bottom);
		}
		data->len_a = lst_len(data->a);
	}
}
/*void	midpoint_a(t_data *data)
{
	int	median;
	int	pos;
	t_node 	*temp;
	t_node	*tail;

	temp = data->a;
	tail = lst_tail(data->a);
	pos = get_first_top(data->a) - get_first_bottom(data->a);
	while (data->len_a > 4)
	{
		data->counter++;
		median = get_median(data->a, data->a->cluster);
		while (temp != tail)
		{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
			if (top < pos || top == pos)
    		{
        		while (top--)
            		ra(&data->a);
        		pa(&data->a)
				temp = data->a;
   		 	}
			else if (top > pos)
			{
				pos++;
				while(pos--)
					rra(&data->a);
				pa(&data->a)
				tail = lst_tail(temp);
			}
		}
			pa(&data->a);
		data->len_a = lst_len(data->a);
	}
}
*/

/* OR: void	midpoint_a(t_data *data)
{
	int	median;

	while (data->len_a > 2)
	{
		data->counter++;
		median = get_median(data->a, data->a->cluster);
		while (data->len_a != 0)
		{
			if (data->a->numb < median)
			{
				data->a->cluster = data->counter;
				pb(&data->b, &data->a);	
			}
			else if (data->a->numb >= median)
				ra(&data->a);
			data->len_a--;
		}
		data->len_a = lst_len(data->a);
	}
}*/

void	midpoint_b(t_data *data)            
{
	int	cluster;
	int	len;

	while (lst_len(data->b) > 0)
	{
		cluster = data->b->cluster;
		len = get_len_cluster(data->b, cluster);
		if (len == 1)
		{
			pa(&data->a, &data->b);
		}
		else if (len == 2)
		{
			if (data->b->numb < data->b->next->numb)
				sb(data->b);
			pa(&data->a, &data->b);
			pa(&data->a, &data->b);
		}
		else
		{
			midpoint_sub_b(data, cluster);
		}
	}
}

void	midpoint_sub_b(t_data *data, int cluster)
{
	int	median;
	int	len;

	
	len = get_len_cluster(data->b, cluster);
	data->counter++;
	if (is_cluster_b_sorted(data->b, cluster) == 1)
		push_to_a(data, len);
	else
	{
		median = get_median(data->b, cluster);
		//printf("midpointsub median: %d, len: %d\n", median, len);
		while (len)
		{
			if (data->b->numb > median)
			{
				data->b->cluster = data->counter;
				pa(&data->a, &data->b);
			}
			else if (data->b->numb <= median)
			{
				rb(&data->b);
				data->rb_count++;
			}
			len--;
		}
		back_to_top(data->rb_count, 'b', data);
		check_a(data, data->counter);
	}
}

void	check_a(t_data *data, int cluster)
{
	int	len;


	len = get_len_cluster(data->a, cluster);
	//printf("in check_a len: %d, cluster: %d\n", len, cluster);
	//lst_print(data->a, 'A', "in checka");
	//lst_print(data->b, 'B', "in checka");
	if (is_cluster_a_sorted(data->a, cluster) == 0)
	{
		if (len <= 2)
			sort_two_a(data);
		else
			midpoint_sub_a(data, cluster, len);
	}
	else
		return ;
}

void	midpoint_sub_a(t_data *data, int cluster, int len)
{
	int	median;


	//lst_print(data->a, 'A', "in midpoint_sub_a");
	//lst_print(data->b, 'B', "in midpoint_sub_a");
	//printf("in midpointsuba\n");
	//printf("counter in midpoint_sub_a: %d\n", counter);
	data->len_a = len;
	//printf("median in midpoint_sub_a: %d\n", median);
	//printf("in midpointsuba len: %d, cluster: %d\n", len, cluster);
	while (data->len_a > 2 && is_cluster_a_sorted(data->a, cluster) == 0)
	{
		data->counter++;
		median = get_median(data->a, cluster);
		while (data->len_a != 0)
		{
			if (data->a->numb < median)
			{
				data->a->cluster = data->counter;
				pb(&data->b, &data->a);
			}	
			else if (data->a->numb >= median)
			{
				ra(&data->a);
				data->ra_count++;
			}
			data->len_a--;
		}
		back_to_top(data->ra_count, 'a', data);
		data->len_a = get_len_cluster(data->a, cluster);
	}
	if (data->len_a == 2)
		sort_two_a(data);
	//lst_print(data->a, 'A', "after midpoint_sub_a");
	//lst_print(data->b, 'B', "after midpoint_sub_a");
}
