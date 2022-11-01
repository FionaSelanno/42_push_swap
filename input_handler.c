/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:03:46 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/01 09:53:17 by fiselann         ###   ########.fr       */
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
			ft_exit(a, tab, 'e');
		if (str[i] >= '0' && str[i] <= '9')
		{
			numb = (numb * 10) + str[i] - 48;
			if (check_limits(numb, neg) == -1)
				ft_exit(a, tab, 'e');
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
	while (tab[elements])
	{
		add_to_lst(a, tab[elements], tab);
		elements++;
	}
	free_tab(tab, elements);
	return (elements);
}

void	check_if_dups(t_node **a, int numb, char **tab)
{
	t_node	*temp;

	if (!a)
		return ;
	temp = *a;
	while (temp)
	{
		if (temp->numb == numb)
			ft_exit(a, tab, 'e');
		temp = temp->next;
	}
}
