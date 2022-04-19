#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

typedef struct list_a
{
	int	numb;
	struct list_a	* next;
} list_a;

/***** list *****/
list_a	*lst_new_item(int value);
void	lst_add_back();
void	lst_add_front();
void 	lst_print(list_a *head);

/**** handle input ****/
int		ft_atoi(char *s);


# endif
