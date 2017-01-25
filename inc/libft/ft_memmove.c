/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:10:51 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:47:04 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	tmp;
	size_t	i;

	i = 0;
	if (dst > src)
	{
		while (len)
		{
			len--;
			((char*)dst)[len] = ((char*)src)[len];
		}
	}
	while (i < len)
	{
		tmp = ((char*)src)[i];
		((char*)dst)[i] = tmp;
		i++;
	}
	return ((char*)dst);
}
