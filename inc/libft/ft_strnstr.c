/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:45:43 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:56:53 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t count;
	size_t s;

	i = 0;
	count = 0;
	s = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i])
	{
		count = i;
		s = 0;
		while ((big[count] == little[s]) && (count < len))
		{
			count++;
			s++;
			if (little[s] == '\0')
				return (&((char*)big)[i]);
		}
		i++;
	}
	return (0);
}
