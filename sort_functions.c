/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:57:28 by fiselann          #+#    #+#             */
/*   Updated: 2022/04/05 12:10:50 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

list_a	*create_new_item_lista(int value)
{
	list_a	*new_item;

	new_item = malloc(sizeof(list_a));
	new_item->numb = value;
	new_item->next = NULL;
	return new_item;

}


int	main(void)
{
	list_a n1, n2, n3;
	list_a *head

}
