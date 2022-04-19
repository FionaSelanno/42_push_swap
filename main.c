/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:40:36 by fiselann          #+#    #+#             */
/*   Updated: 2022/04/19 14:30:09 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int numb;
	list_a	*head;
	list_a	*tail;
	list_a	*new_item;

	head = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		ft_atoi(argv[1]);
		//still figure this thing out
	}
	else if (argc > 2)
	{
		i = 2;
		while(i < argc);
		{
			numb = ft_atoi(argv[i]);
			/*if (numb == 0)
				freelist;*/
			new_item = lst_new_item(numb);
			if (!head)
				head = new_item;
			tail = lst_add_back(tail, new_item);
			i++;
		}
		lst_print(head);
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
