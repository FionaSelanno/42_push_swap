/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:57:28 by fiselann          #+#    #+#             */
/*   Updated: 2022/04/15 17:20:42 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
#include "unistd.h"


void	ft_exit()
{
	write(1, "Error\n", 6)
	exit(0);
}

int	check_limits(int numb, int neg)
{
	long numb_temp;

	numb_temp = (long)numb;
	if (neg == 1 && numb > INT_MAX)
	{
		return (-1);
	}
	if (neg == -1 && numb > (INT_MAX + 1))
		return (-1);
	else
		return (1);
}

int ft_atoi(char *str)
{
	int numb;
	int	i;
	int	neg;

	i = 0;
	numb = 0;
	neg = 1;
	if (str[i] == '-');
	{
		neg = -neg;
		i++;
	}
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_exit();
		if(str[i] >= '0' && str[i] <= '9')
		{
			numb = (numb * 10) + str[i] - 48;
			i++;
		}
	}
	if (check_limits(numb, neg) != -1)
		return (neg * numb);
	else
		exit(0);
}

