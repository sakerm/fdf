/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:08:39 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:46:09 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*value;
	unsigned char	*s1;
	size_t			l;

	value = NULL;
	s1 = ((unsigned char*)s);
	l = 0;
	while (l < n)
	{
		if (s1[l] == (unsigned char)c)
			return (&s1[l]);
		l++;
	}
	return (NULL);
}
