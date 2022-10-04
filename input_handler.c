/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:03:46 by fiselann          #+#    #+#             */
/*   Updated: 2022/05/11 16:45:42 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_limits(unsigned long long numb, int neg)
{
	if (neg == 1 && numb > INT_MAX)
	{
		return (-1);
	}
	if (neg == -1 && numb > ((unsigned long long)INT_MAX + 1))
		return (-1);
	else
		return (1);
}

int ft_atoi(char *str)
{
	unsigned long long numb;
	int	i;
	int	neg;

	i = 0;
	numb = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -neg;
		i++;
	}
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_exit(1);
		if(str[i] >= '0' && str[i] <= '9')
		{
			numb = (numb * 10) + str[i] - 48;
			if(check_limits(numb, neg) == -1)
				ft_exit(2);
		}
		i++;
	}
	return (neg * numb);
}

int	check_if_duplicates(list_ints *head_a)
{
	list_ints	*ptr1;
	list_ints	*ptr2;
	
	ptr1 = head_a;
	while (ptr1 != NULL && ptr1->next != NULL)
	{
		ptr2 = ptr1;
		while (ptr2->next != NULL)
		{
			if (ptr1->numb == ptr2->next->numb)
				ft_exit(3);
			ptr2 = ptr2->next;
		}		
		ptr1 = ptr1->next;
	}
	return (0);
}
