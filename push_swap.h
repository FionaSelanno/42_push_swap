/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:01:22 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/02 10:09:59 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				numb;
	int				og;
	int				cluster;
	struct s_node	*next;
}	t_node;

typedef struct s_data
{
	t_node	*a;
	t_node	*b;
	int		len_a;
	int		rb_count;
	int		ra_count;
	int		counter;
}	t_data;

/***** list *****/
t_node	*lst_new_item(int value, t_node **a, char **tab);
void	lst_addback(t_node **lst, t_node *item_to_add);
size_t	lst_len(t_node *head);
int		create_lst(int argc, char **argv, t_node **head);
void	add_to_lst(t_node **a, char *str, char **tab);
t_node	*lst_tail(t_node *head);

/**** handle input ****/
int		check_limits(unsigned long long numb, int neg);
int		ft_atoi(char *str, t_node **a, char **tab);
void	check_if_dups(t_node **a, int numb, char **tab);
int		handle_one_arg(char *str, t_node **a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tabsize(char const *s, char c);
void	*free_tab(char **tab, int n);
void	*ft_filltab(char **tab, char const *s, char c);
char	**ft_split(char const *s, char c);
void	free_lst(t_node **head);

/**** handle array ****/
int		*put_a_in_arr(t_node *a, int len);
int		partition(int *arr, int low, int high);
void	quick_sort(int *arr, int low, int high);
void	set_newval(int *sorted, t_node *a, int len);
void	change_lstval(t_node *a);

/**** operations ****/
void	sa(t_node *a);
void	sb(t_node *b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	shift_up_elem(t_node **head);
void	ra(t_node **a);
void	rb(t_node **b);
void	shift_down_elem(t_node **head);
void	rra(t_node **a);
void	rrb(t_node **b);

/**** sort functions small ****/
void	sort_two_a(t_data *data);
void	sort_three_a(t_data *data);
void	sort_four_five_a(t_data *data, int elem_count);
int		find_position_in_list(t_data *data, int numb_to_find);
void	sort_by_position(t_data *data, size_t position);

/**** sort functions big ****/
void	midpoint_a(t_data *data);
void	midpoint_b(t_data *data);
void	midpoint_sub_b(t_data *data, int cluster);
void	midpoint_sub_a(t_data *data, int cluster, int len);
void	big_sort(t_data *data);
void	shift_to_b(int median, t_node **a, size_t len);
void	push_to_a(t_data *data, int len);

/**** utils ***/
void	ft_exit(t_node **a, char **tab, char c);
void	ft_swap_numb(int *x, int *y);
int		get_median(t_node *head, int cluster);
void	data_init(t_data *data, t_node **a);
void	set_data(t_data *data, int cluster);
void	set_cluster(t_node *head, int cluster);
int		is_a_sorted(t_node *a);
int		is_cluster_a_sorted(t_node *a, int cluster);
int		is_cluster_b_sorted(t_node *b, int cluster);
int		get_len_cluster(t_node *head, int cluster);
void	back_to_top(int count, char c, t_data *data);
void	check_a(t_data *data, int cluster);
void	sort_to_bottom_half(size_t count, t_data *data);
size_t	ft_strlen(const char *str);
size_t	ft_strlen_double(char **str);
void	choose_action_a(t_data *data, int median);
void	choose_action_b(t_data *data, int median);

/**** main ***/
void	pick_sort(int elem_count, t_data *data);

#endif
