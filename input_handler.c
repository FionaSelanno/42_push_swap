/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:03:46 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/24 09:19:34 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*undo of this ft*/
void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		//printf("tab[%d] = %s\n", i, tab[i]);
		i++;
	}
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

int	ft_atoi(char *str, t_node **a, char **tab)
{
	unsigned long long	numb;
	int					i;
	int					neg;

	i = 0;
	numb = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -neg;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_exit(1, a, tab);
		if (str[i] >= '0' && str[i] <= '9')
		{
			numb = (numb * 10) + str[i] - 48;
			if (check_limits(numb, neg) == -1)
				ft_exit(2, a, tab);
		}
		i++;
	}
	return (neg * numb);
}

int	handle_one_arg(char *str, t_node **a)
{
	char	**tab;
	int		elements;

	elements = 0;
	tab = ft_split(str, ' ');
	if (!tab)
		return (0);
	print_tab(tab);
	while (tab[elements])
	{
		//printf("elements: %d\n", elements); /*delete this*/
		add_to_lst(a, tab[elements], tab);
		elements++;
	}
	return (elements);
}

void	check_if_dups(t_node **a, int numb, char **tab)
{
	t_node	*temp;

	if (!a)
		return ;
	temp = *a;
	//lst_print(*a, 'A', "check_dups");
	//printf("numb: %d", numb);
	while (temp)
	{
		if (temp->numb == numb)
			ft_exit(3, a, tab);
		temp = temp->next;
	}
}
