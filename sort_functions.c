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
	write(1, "Error\n", 6);
	exit(0);
}

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


