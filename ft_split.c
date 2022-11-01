/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiselann <fiselann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:41:44 by fiselann          #+#    #+#             */
/*   Updated: 2022/11/01 10:23:42 by fiselann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tabsize(char const *s, char c)
{
	size_t	count_words;
	size_t	i;
	size_t	toggle;

	i = 0;
	count_words = 0;
	toggle = 0;
	while (s[i])
	{
		if (s[i] != c && toggle == 0)
		{
			toggle = 1;
			count_words++;
		}
		else if (s[i] == c)
			toggle = 0;
		i++;
	}
	return (count_words);
}

void	*free_tab(char **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (tab);
}

void	*ft_filltab(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	lenword;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		lenword = 0;
		while (s[i] && s[i] != c)
		{
			lenword++;
			i++;
		}
		if (lenword > 0)
		{
			tab[j++] = ft_substr(s, (i - lenword), lenword);
			if (tab[j - 1] == NULL)
				return (free_tab(tab, (j - 1)));
		}
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_tabsize(s, c)) + 1);
	if (!tab)
		return (NULL);
	ft_filltab(tab, s, c);
	return (tab);
}
