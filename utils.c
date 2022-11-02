/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:22:39 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/02 10:10:31 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_exit(t_node **a, char **tab, char c)
{
	int		len;

	free_lst(a);
	if (tab != NULL)
	{
		len = ft_strlen_double(tab);
		free_tab(tab, len);
	}
	if (c == 'e')
		write(1, "Error\n", 6);
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
