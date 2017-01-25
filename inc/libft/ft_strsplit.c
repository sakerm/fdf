/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:24:42 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:56:25 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_countw(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while ((s[i] == c) && (s[i]))
			i++;
		if ((s[i] != c) && (s[i]))
		{
			i++;
			j++;
			while ((s[i] != c) && (s[i]))
				i++;
		}
	}
	return (j);
}

static int		ft_countwlen(const char *s, char c)
{
	int		i;

	i = 0;
	while ((s[i] != c) && (s[i]))
		i++;
	return (i);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		n;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	n = ft_countw(s, c);
	i = 0;
	j = 0;
	if ((tab = (char **)malloc(sizeof(char *) * n + 1)) == NULL)
		return (NULL);
	while (i < n)
	{
		while (s[j] == c)
			j++;
		tab[i] = ft_strsub(&s[j], 0, ft_countwlen(&s[j], c));
		j = j + ft_countwlen(&s[j], c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
