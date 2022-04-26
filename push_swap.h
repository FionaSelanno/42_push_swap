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
void	lst_addback(list_a *head, list_a *item_to_add);
list_a	*lst_addback_tailreturn(list_a *tail, list_a *item_to_add);
void	lst_addfront(list_a *head, list_a *item_to_add);
void 	lst_print(list_a *head);

/**** handle input ****/
int	ft_atoi(char *s);
int	check_limits(unsigned long long numb, int neg);
int	ft_atoi(char *str);

# endif
