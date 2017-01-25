/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:15:20 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:50:53 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;
	int		i;

	c1 = (char)c;
	i = 0;
	if (c1 == '\0')
	{
		while (s[i])
			i++;
		return (&((char*)s)[i]);
	}
	while (s[i])
	{
		if (s[i] == c1)
			return (&((char*)s)[i]);
		i++;
	}
	return (NULL);
}
