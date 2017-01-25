/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:56:20 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:55:32 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	c;

	c = 0;
	if ((str = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (c <= size)
	{
		str[c] = 0;
		c++;
	}
	return (str);
}
