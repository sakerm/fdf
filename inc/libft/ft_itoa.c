/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:48:58 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:58:31 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static long		ft_intlen(long n)
{
	long	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = 1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		*ft_core(long n, char *str)
{
	long	len;

	len = ft_intlen(n);
	if (n < 0)
		n = -n;
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

char			*ft_itoa(int nb)
{
	char	*str;
	int		i;
	long	n;

	if ((str = (char *)malloc(ft_intlen(nb) + 1 * (sizeof(char)))) == NULL)
		return (NULL);
	i = 0;
	n = nb;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	return (ft_core(n, str));
}
