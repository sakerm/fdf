/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:20:03 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:54:38 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t count;

	count = 0;
	i = 0;
	while (s1[count])
		count++;
	while (i < n && s2[i])
	{
		s1[count] = s2[i];
		i++;
		count++;
	}
	s1[count] = '\0';
	return (s1);
}
