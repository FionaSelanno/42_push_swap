/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:38:51 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/25 12:00:39 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_node	*lst_new_item(int value, t_node **a, char **tab)
{
	t_node	*new_item;

	new_item = (t_node *)malloc(sizeof(t_node));
	if (!new_item)
		ft_exit(4, a, tab);
	new_item->numb = value;
	new_item->cluster = 0;
	new_item->next = NULL;
	return (new_item);
}

void	lst_print(t_node *head, char c, char *info)
{
	t_node	*temp;

	temp = head;
	printf("STACK %c (%s):\n", c, info);
	while (temp != NULL)
	{
		printf("numb: %d og: %d - cluster:%d\n",
			temp->numb, temp->og, temp->cluster);
		temp = temp->next;
	}
}

int	create_lst(int argc, char **argv, t_node **a )
{
	int		elements;

	elements = 1;
	while (elements < argc)
	{
		add_to_lst(a, argv[elements], NULL);
		elements++;
	}
	return (elements - 1);
}

void	add_to_lst(t_node **a, char *str, char **tab)
{
	t_node	*new_item;
	int		numb;

	numb = ft_atoi(str, a, tab);
	check_if_dups (a, numb, tab);
	new_item = lst_new_item(numb, a, tab);
	lst_addback(a, new_item);
}

void	lst_addback(t_node **lst, t_node *item_to_add)
{
	t_node	*temp_head;

	if (*lst == NULL)
	{
		*lst = item_to_add;
		return ;
	}
	temp_head = *lst;
	while (temp_head->next != NULL)
	{
			temp_head = temp_head->next;
	}
	temp_head->next = item_to_add;
}
