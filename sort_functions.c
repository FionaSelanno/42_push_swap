/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:57:28 by fiselann          #+#    #+#             */
/*   Updated: 2022/04/05 16:57:54 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
#include "unistd.h"

list_a	*create_new_item_lista(int value)
{
	list_a	*new_item;

	new_item = malloc(sizeof(list_a));
	new_item->numb = value;
	new_item->next = NULL;
	return new_item;

}

void printList(list_a *head)
{
	list_a *temp;

	temp = head;
	while (temp != NULL)
	{
		printf("item: %d\n", temp->numb);
		temp = temp->next;
	}
}

void	ft_exit()
{
	write("1, Error\n", 6)
	exit();
}

int	check_limits(int numb, int neg)
{
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

void	free_list(list_a *head)
{
	list_a *temp;

	//figure this out
}

int	main(int argc, char **argv)
{
	int	i;
	int numb;
	
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		ft_atoi(argv[1]);
		//still figure this thing out
	}
	if (argc > 2)
	{
		i = 3;
		while(argc > i);
		{
			printf("after atoi: %d\n", ft_atoi(argv[i]));
			
		}
	}

	else
		printf("Error\n");
	/*
	list_a n1, n2, n3;
	list_a	*head;

	n1.numb = 1;
	n2.numb = 2;
	n3.numb = 3;

	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	printList(head);
	*/
}
