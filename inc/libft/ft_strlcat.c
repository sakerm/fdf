/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:18:15 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/10 19:53:22 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		destlen;

	destlen = ft_strlen(dst);
	if (size <= destlen)
		return (size + ft_strlen(src));
	ft_strncat(dst, src, size - destlen - 1);
	return (destlen + ft_strlen(src));
}
