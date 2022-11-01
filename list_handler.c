/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:38:51 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/30 18:59:57 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new_item(int value, t_node **a, char **tab)
{
	t_node	*new_item;

	new_item = (t_node *)malloc(sizeof(t_node));
	if (!new_item)
		ft_exit(a, tab, 'e');
	new_item->numb = value;
	new_item->cluster = 0;
	new_item->next = NULL;
	return (new_item);
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
	if (is_a_sorted(*a) == 1)
		ft_exit(a, NULL, 0);
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

void	lst_addback(t_node **head, t_node *item_to_add)
{
	t_node	*tail;

	if (!head)
		return ;
	if (*head == NULL)
		*head = item_to_add;
	else
	{
		tail = lst_tail(*head);
		tail->next = item_to_add;
	}
}
