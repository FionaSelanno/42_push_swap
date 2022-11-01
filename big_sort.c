/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:16:11 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/30 17:02:10 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	midpoint_a(t_data *data)
{
	int	median;

	while (data->len_a > 4)
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
}

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
		while (len)
		{
			choose_action_b(data, median);
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

	data->len_a = len;
	while (data->len_a > 2 && is_cluster_a_sorted(data->a, cluster) == 0)
	{
		data->counter++;
		median = get_median(data->a, cluster);
		while (data->len_a != 0)
		{
			choose_action_a(data, median);
			data->len_a--;
		}
		back_to_top(data->ra_count, 'a', data);
		data->len_a = get_len_cluster(data->a, cluster);
	}
	if (data->len_a == 2)
		sort_two_a(data);
}
