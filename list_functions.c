/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:38:51 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/04 10:42:13 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

list_ints	*lst_new_item(int value, int i)
{
	list_ints	*new_item;

	new_item = (list_ints*)malloc(sizeof(list_ints));
	if(!new_item)
		ft_exit(4);
	new_item->numb = value;
	new_item->cluster = i;
	new_item->next = NULL;
	return new_item;
}

void lst_print(list_ints *head, char c, char *info)
{
	list_ints *temp;

	temp = head;
	printf("STACK %c (%s):\n", c, info);
	while (temp != NULL)
	{
		printf("numb: %d - cluster:%d, counter: %d\n", temp->numb, temp->cluster, temp->counter);
		temp = temp->next;
	}
}

/*int  lst_create(int	argc, char **argv, list_ints **head)
{
	int			element_count;
	int			numb;
	list_ints	*new_item;
	list_ints	*tail;

	element_count  = 1;
	while(element_count < argc)
	{
		numb = ft_atoi(argv[element_count], &head);
		new_item = lst_new_item(numb);
		if (!head)
			head = new_item;
		tail = lst_addback(tail, new_item);
		element_count++;
	}
	lst_print(head);
	return (element_count - 1);
}*/

/* add item_to_add to the tail of the list and return the new tail */
list_ints	*lst_addback(list_ints *tail, list_ints *item_to_add)
{
	if (!tail)
		tail = item_to_add;
	else
		tail->next = item_to_add;
	return (item_to_add);	
}

void	lst_addfront(list_ints **head, list_ints *item_to_add)
{
	if (item_to_add != NULL)
	{	
		item_to_add->next = *head;
		*head = item_to_add;
	}
}

list_ints	*lst_gettail(list_ints *head)
{
	if (!head)
		return NULL;
	while (head->next != NULL)
		head = head->next;
	return (head);
}

size_t	lst_len(list_ints *head)
{
	list_ints *temp;
	int	len;

	temp = head;
	len = 0;
	printf("here4?\n");
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

list_ints	*lst_last_node(list_ints *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}
/*void	lst_freeall(list_ints **head)
{
	list_ints	*temp_head;
	
	if (!*head)
		return ;
	temp_head = *head;
	while(*head)
	{
		temp_head = (*head)->next;
		free(head);
		*head = temp_head;
		//check if I should the delete the content of the items as well
	}
	*head = NULL;
}*/

