/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:17:29 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:52:07 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*string;

	a = 0;
	while (s1[a])
		a++;
	string = (char*)malloc(sizeof(char) * (a + 1));
	if (!(string != (char*)malloc(sizeof(char) * a + 1)))
		return (NULL);
	a = 0;
	while (s1[a])
	{
		string[a] = s1[a];
		a++;
	}
	string[a] = '\0';
	return (string);
}
