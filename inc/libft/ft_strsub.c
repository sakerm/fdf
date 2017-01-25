/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:18:51 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:57:23 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	start1;
	char	*str;

	i = 0;
	start1 = (size_t)start;
	if (!(s))
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (i < len)
	{
		if (i < len && s[start1] == '\0')
			return (NULL);
		str[i] = s[start1];
		start1++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
