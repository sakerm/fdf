/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:26:14 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:56:37 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int s;
	int o;

	i = 0;
	s = 0;
	o = 0;
	if (*little == '\0')
		return (((char*)big));
	while (big[s])
	{
		s = o;
		while (big[s] == little[i])
		{
			i++;
			s++;
			if (little[i] == '\0')
				return (&((char*)big)[s - i]);
		}
		i = 0;
		o++;
	}
	return (NULL);
}
