#include "push_swap.h"
#include <stdio.h>

int     *put_in_array(list_ints *head, int cluster)
{
    int    *array_ints;
    int     index;

    array_ints = malloc(sizeof(int) * lst_len(head));
    index = 0;
    while(head != NULL)
    {
        array_ints[index++] = head->numb;
        head->cluster = cluster;
        head = head->next;
    }
    return (array_ints);
}

/* to find the median, you have to sort the array first*/
void    quick_sort_arr(int *arr, int low, int high)
{
    int pivot_index;

    if (low < high)
    {
        pivot_index = partition(arr, low, high);
        quick_sort_arr(arr, low, (pivot_index - 1));
        quick_sort_arr(arr, (pivot_index + 1), high);    
    }
}

int  partition(int *arr, int low, int high)
{
    int  i;
    int  j;
    int pivot_value;

    i = low;
    j = low;
    pivot_value = arr[high];
    while (j < high)
    {
        if (arr[j] < pivot_value)
        {
            ft_swap_numb(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    ft_swap_numb(&arr[i], &arr[high]);
    return (i);
}

void ft_printarray(int *arr, int len)
{
    int i = 0;
    while (i < len)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

/* main to test quicksort
 * > gcc -Wall -Wextra -Werror big_sort.c input_handler.c list_functions.c utils.c arr_functions.c
 * >./a.out
 * >./a.out 3 7 5 1 2 6 //is working
 * >./a.out 3 5 2 100 30 90 //is not working, it's because I was using size_t as a datatype for the index
*/

/*#include <stdio.h>

void    arr_print(int *arr, int len, char *info)
{
    int i = 0;
    printf("%s: ", info);
    while (i < len)
    {
        printf("%d ", arr[i++]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int	elements;
	int	numb;
	list_ints	*head_a;
	list_ints	*tail_a;
	list_ints	*new_item;
    int *arr;

    head_a = tail_a = new_item = NULL;

    if (argc > 2)
    {
        elements = 1;
		while (elements < argc)
		{
			numb = ft_atoi(argv[elements]);
			new_item = lst_new_item(numb);
			if (!head_a)
				head_a = new_item;
			tail_a = lst_addback(tail_a, new_item);
			elements++;
		}
        printf("elements count: %d\n", (elements - 1));
        arr = put_in_array(head_a);
        arr_print(arr, elements - 1, "before quick_sort");
        quick_sort_arr(arr, 0, elements - 2);
        arr_print(arr, elements - 1, "after quick_sort");
        free(arr);
    }
    return (0);
}
*/