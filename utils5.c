#include "push_swap.h"

t_node   *best_move(t_data *data, int top, int bottom)
{
	t_node  *updated;
	t_node  *node_topush;

	if (top <= bottom)
	{
		node_topush = get_topush(top, data->a);
		choose_shiftup(top, data, node_topush);
		pb(&data->a);
		updated = data->a;
		return updated;
	}
	else if (top > bottom)
	{
		node_topush = get_topush(ix_first_bottom())
		choose_shiftdown()
		pb(&data->a);
		updated = lst_tail(data->a);
		return updated;
}

/*gets the index of the first node less then median, counted from the top off the list*/
int  ix_first_top(t_node *head, int median)
{
	int pos;

	pos = 0;
	while (head)
	{
		if (head->numb <= median)
			break;
		pos++;
		head = head->next;
	}
	return (pos);
}

/*gets the first node less then median, counted from the bottom off the list*/
int ix_first_bottom(t_node *head, int median)
{
	int     pos;
	int     i;
	t_node  *current;

	pos = 0;
	i = 0;
	while (head)
	{
		if (head->numb <= median)
			pos = i;
		i++; 
		head = head->next;
	}
	return (pos);
}
 /* instead of pushing the node on top off b I try to push the node in the righ position in list b.*/
void choose_shiftup(int count, t_data *data, t_node *topush)
{
	while (count && data->a)
	{
		if (data->b->numb > topush->numb) //check if it's still possible iff *b==NULL*/
			rr(&data->a, &data->b);
		else
			ra(&data->a);
		count--;
	}
}

void choose_shiftdown(int count, t_data *data, t_node *topush)
{
	t_node *tail;
	
	while (count)
	{
		tail = lst_tail(data->b);
		if (tail->numb < data->b->numb)
			rra(&data->a, &data->b);
		else
			rrr(&data->a, &data->b);
		count--;
	}
}

t_node	*get_topush(int len, t_node *head)
{
	t_node  *topush;

	while (len)
	{
		head = head->next;
		len--;
	}
	topush = head;
}