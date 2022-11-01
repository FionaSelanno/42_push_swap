/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:33:30 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/01 10:31:23 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_len_cluster(t_node *head, int cluster)
{
	int	len;

	len = 0;
	while (head != NULL && head->cluster == cluster)
	{
		len++;
		head = head->next;
	}
	return (len);
}

void	push_to_a(t_data *data, int len)
{
	while (len)
	{
		pa(&data->a, &data->b);
		len--;
	}
}

void	back_to_top(int count, char c, t_data *data)
{
	while (count)
	{
		if (c == 'a')
			rra(&(data->a));
		else if (c == 'b')
			rrb(&(data->b));
		count--;
	}
	if (c == 'b')
		data->rb_count = 0;
	else if (c == 'a')
		data->ra_count = 0;
}

size_t	ft_strlen_double(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
