/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 21:45:37 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:57:46 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s)
{
	char	*dup;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen((char*)s) - 1;
	k = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j != 0)
		j--;
	if (j < i)
		j = ft_strlen((char*)s);
	if ((dup = (char *)malloc(sizeof(char) * ((j - i) + 2))) == 0)
		return (NULL);
	while (i <= j)
		dup[k++] = s[i++];
	dup[k] = '\0';
	return (dup);
}
