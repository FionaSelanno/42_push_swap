/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:22:39 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/24 17:09:59 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_exit(int error_numb, t_node **a, char **tab)
{
	t_node	*temp;
	int		len;

	printf("Error: %d\n", error_numb);
	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	*a = NULL;
	if (tab != NULL)
	{
		len = ft_strlen(*tab);
		free_tab(tab, len);
	}
	exit(0);
}

void	ft_swap_numb(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	data_init(t_data *data, t_node **a)
{
	data->a = *a;
	data->b = NULL;
	data->len_a = 0;
	data->rb_count = 0;
	data->ra_count = 0;
	data->count = 0;
	data->counter = 0;
}

int	get_median(t_node *head, int cluster)
{
	size_t	sum;
	size_t	len;

	sum = 0;
	len = 0;
	while (head)
	{
		if (head->cluster != cluster)
			break ;
		sum += head->numb;
		len++;
		head = head->next;
	}
	return ((int)(sum / len));
}

void	set_data(t_data *data, int cluster)
{
	set_cluster(data->a, cluster);
	data->len_a = lst_len(data->a);
	data->rb_count = 0;
	data->ra_count = 0;
}
