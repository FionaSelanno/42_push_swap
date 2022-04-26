/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:38:51 by fiselann          #+#    #+#             */
/*   Updated: 2022/04/19 15:57:51 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

list_a	*lst_new_item(int value)
{
	list_a	*new_item;

	new_item = (list_a*)malloc(sizeof(list_a));
	if(!new_item)
		return NULL;
	new_item->numb = value;
	new_item->next = NULL;
	return new_item;

}

void lst_print(list_a *head)
{
	list_a *temp;

	temp = head;
	while (temp != NULL)
	{
		printf("item: %d\n", temp->numb);
		temp = temp->next;
	}
}

/* Make a temp_head to use it to travers the list. Don't use head to traverse the list, otherwise you lose track of the first element
 * if head is NULL then there is no list thus the item_to_add will be the first element
 * Traverse the list and stop when you've reached the last item, where temp_head->next == NULL;
 * The last item is reached, get out off the loop and let next of this item to point to item_to_add;
 * This function takes a long time, when you have a long list. Because everytime you want to add a new item to the list, you have to traverse the list to get to the end. For timeout prevention, it is better to track tail off the list.
 */

 void lst_addback(list_a *head, list_a *item_to_add)
{
	list_a	*temp_head;

	if (!head)
		head = item_to_add;
	temp_head = head;
	while(temp_head->next != NULL)
		temp_head = temp_head->next;
	temp_head->next = item_to_add;
}

/* add item_to_add to the tail of the list and return the new tail */
list_a	*lst_addback_tailreturn(list_a *tail, list_a *item_to_add)
{
	if (!tail)
		tail = item_to_add;
	else
		tail->next = item_to_add;
	return (item_to_add);	
}

void lst_add_front(list_a *head, list_a *item_to_add)
{
	list_a *temp;
	
	temp = NULL;
	temp->next = head;
	temp = item_to_add;
}

void	free_list_all(list_a *head)
{
	(void) head;
	//figure this out:x
	
}

