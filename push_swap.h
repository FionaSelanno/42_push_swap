/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:01:22 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/04 09:39:39 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

//TODO: rename structs with s_<name> and t_<name>
typedef struct list_ints
{
	int	numb;
	int cluster;
	int counter;
	struct list_ints	*next;
} list_ints;

//TODO: rename structs with s_<name> and t_<name>
typedef struct data
{
	list_ints *head_a;
	list_ints *head_b;
	int len_a;
	int rb_count;
	int	ra_count;
	int count;
} data;

/***** list *****/
list_ints	*lst_new_item(int value, int i);
list_ints	*lst_addback(list_ints *tail, list_ints *item_to_add);
void		lst_addfront(list_ints **head, list_ints *item_to_add);
size_t		lst_len(list_ints *head);
void 		lst_print(list_ints *head, char c, char *info);
//void		lst_freeall(list_ints **head);
int			lst_create(int argc, list_ints **head);
list_ints	*lst_gettail(list_ints *head);

/**** array *****/
int		*put_in_array(list_ints *head, int cluster);
void	quick_sort_arr(int *arr, int low, int high);
int		partition(int *arr, int low, int high);
void	ft_printarray(int *arr, int len);

/**** handle input ****/
int	check_limits(unsigned long long numb, int neg);
int	ft_atoi(char *str);
int	check_if_duplicates(list_ints *head_a);

/**** operations ****/
void	sa(list_ints *head_a);
void	sb(list_ints *head_b);
void	ss(list_ints *head_a, list_ints *head_b);
void	pa(list_ints **head_a, list_ints **head_b);
void	pb(list_ints **head_b, list_ints **head_a);
void	ra(list_ints **head_a);
void	rb(list_ints **head_b);
void	rr(list_ints **head_a, list_ints **head_b);
void	rra(list_ints **head_a);
void	rrb(list_ints **head_b);
void	rrr(list_ints **head_a, list_ints **head_b);

/**** sort functions small ****/
void	sort_two_a(data *data);
void	sort_three_a(data *data);
void	sort_four_five_a(data *data, int elem_count);
int		find_position_in_list(list_ints *head_a, int numb_to_find);
void	sort_by_position(list_ints **head_a, list_ints **head_b, size_t position);

/**** sort functions big ****/
void	midpoint_a(data *data);
void	midpoint_b(data *data);
void	midpoint_sub_b(data *data, int cluster, int counter);
void	check_a(data *data, int cluster, int counter);
void	midpoint_sub_a(data *data, int cluster, int counter);
void	big_sort(data *data);
void	shift_to_b(int median, list_ints **head_a, size_t len);
void	sort_b(data *data, int cluster, int counter);

/**** utils ***/
void	ft_exit(int error_numb);
void	ft_swap_numb(int *x, int *y);
int		get_median(list_ints *head, int cluster);
void	data_init(data *data, list_ints **head_a);
void	set_data(data *data, int cluster, int counter);
void	set_cluster(list_ints *head, int cluster);
void	set_counter(list_ints *head, int cluster, int counter);
int 	is_a_sorted(list_ints *head_a);
int		is_cluster_a_sorted(list_ints *head_a, int cluster, int counter);
int		is_cluster_b_sorted(list_ints *head_b, int cluster, int counter);
int		get_len_cluster(list_ints *head, int cluster);
int		get_len_counter(list_ints *head, int cluster, int counter);

/**** main ***/
void	pick_sort(int elem_count, data *data);

# endif