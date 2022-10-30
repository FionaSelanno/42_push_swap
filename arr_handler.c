/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:49:13 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/24 09:17:42 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*put_a_in_arr(t_node *a, int len)
{
	int	index;
	int	*arr;

	arr = malloc(sizeof(int) * len);
	if (!arr || !a)
		return (NULL);
	index = 0;
	while (index < len)
	{
		arr[index] = a->numb;
		index++;
		a = a->next;
	}
	return (arr);
}

int	partition(int *arr, int low, int high)
{
	int	pivot_value;
	int	i;
	int	j;

	pivot_value = arr[high];
	i = low;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot_value)
		{
			ft_swap_numb(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	ft_swap_numb(&arr[i], &arr[high]);
	return (i);
}

void	quick_sort(int *arr, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

void	set_newval(int *sorted, t_node *a, int len)
{
	int	i;
	t_node *temp;

	temp = a;
	while (a != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (a->numb == sorted[i])
			{
				a->og = i;
			}
			i++;
		}
		a = a->next;
	}
	while (temp != NULL)
	{
		ft_swap_numb(&temp->numb, &temp->og);
		temp = temp->next;
	}
}

void	change_lstval(t_node *a)
{
	int	*arr;
	int	len;

	len = lst_len(a);
	arr = put_a_in_arr(a, len);
	quick_sort(arr, 0, len - 1);
	set_newval(arr, a, len);
	free(arr);
}

/*void ft_printarray(int *arr, int len, char *info)
{
    int i = 0;
    if (!arr)
        return ;
    printf("%s\n", info);
    while (i < len)
    {
        printf("%d, ", arr[i]);
        i++;
    }
    printf("\n");
}*/
