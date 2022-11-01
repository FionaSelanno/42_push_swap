/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:28:39 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/01 10:29:10 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_bottom_half(size_t count, t_data *data)
{
	back_to_top((count - 1), 'a', data);
	pa(&(data->a), &(data->b));
	while (count > 0)
	{
		ra(&(data->a));
		count--;
	}
}

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	substr = malloc(sizeof(*substr) * len + 1);
	if (!substr)
		return (NULL);
	if (start >= ft_strlen(s))
		substr[0] = '\0';
	else
	{
		while (len > 0)
		{
			substr[i++] = s[start++];
			len--;
		}
		substr[i] = '\0';
	}
	return (substr);
}

void	choose_action_a(t_data *data, int median)
{
	if (data->a->numb < median)
	{
		data->a->cluster = data->counter;
		pb(&data->b, &data->a);
	}	
	else if (data->a->numb >= median)
	{
		ra(&data->a);
		data->ra_count++;
	}
}

void	choose_action_b(t_data *data, int median)
{
	if (data->b->numb > median)
	{
		data->b->cluster = data->counter;
		pa(&data->a, &data->b);
	}
	else if (data->b->numb <= median)
	{
		rb(&data->b);
		data->rb_count++;
	}
}
