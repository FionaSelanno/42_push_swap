/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:36:26 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/30 16:46:33 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_data *data)
{
	if (is_cluster_a_sorted(data->a, data->a->cluster) == 1)
		return ;
	else
		sa(data->a);
}

void	sort_three_a(t_data *data)
{
	if (data->a->numb > data->a->next->numb
		&& data->a->numb < data->a->next->next->numb)
		sa(data->a);
	else if (data->a->numb < data->a->next->numb
		&& data->a->numb > data->a->next->next->numb)
		rra(&data->a);
	else if (data->a->numb > data->a->next->numb
		&& data->a->numb > data->a->next->next->numb
		&& data->a->next->numb < data->a->next->next->numb)
		ra(&data->a);
	else if (data->a->numb > data->a->next->numb
		&& data->a->numb > data->a->next->next->numb
		&& data->a->next->numb > data->a->next->next->numb)
	{
		ra(&data->a);
		sa(data->a);
	}
	else if (data->a->numb < data->a->next->numb
		&& data->a->numb < data->a->next->next->numb
		&& data->a->next->numb > data->a->next->next->numb)
	{
		sa(data->a);
		ra(&data->a);
	}
}

void	sort_four_five_a(t_data *data, int elements)
{
	size_t	position;

	while (elements - 3)
	{
		pb(&data->b, &data->a);
		elements--;
	}
	sort_three_a(data);
	while (data->b != NULL)
	{
		position = find_position_in_list(data, data->b->numb);
		sort_by_position(data, position);
	}
}

int	find_position_in_list(t_data *data, int numb_to_find)
{
	unsigned int	position;
	t_node			*temp;

	temp = data->a;
	position = 0;
	while (temp != NULL)
	{
		if (numb_to_find > temp->numb)
			position++;
		if (numb_to_find < temp->numb)
			break ;
		temp = temp->next;
	}
	return (position);
}

void	sort_by_position(t_data *data, size_t position)
{
	size_t	count;
	size_t	len;

	len = lst_len(data->a);
	if (position <= (len / 2 + 1))
	{
		count = position;
		while (position)
		{
			ra(&(data->a));
			position--;
		}
		pa(&(data->a), &(data->b));
		back_to_top(count, 'a', data);
	}
	else if (position > (len / 2 + 1))
		sort_to_bottom_half((len - position + 1), data);
}
