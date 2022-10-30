/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:28:39 by fiselann          #+#    #+#             */
/*   Updated: 2022/10/22 10:47:38 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	write(1, "\n", 1);
}
