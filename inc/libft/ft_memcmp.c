/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:10:26 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:46:19 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			i;
	int				result;

	string1 = ((unsigned char*)s1);
	string2 = ((unsigned char*)s2);
	i = 0;
	result = 0;
	while (i < n)
	{
		if (string1[i] != string2[i])
		{
			result = result + (string1[i] - string2[i]);
			return (result);
		}
		i++;
	}
	return (0);
}
