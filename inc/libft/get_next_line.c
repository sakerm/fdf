/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:54:31 by lomeress          #+#    #+#             */
/*   Updated: 2017/01/23 16:22:01 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	verif_end_of_file(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_new_malloc(char *stock, char *buf, int i)
{
	char	*new;

	new = ft_memalloc(ft_strlen(stock) + i + 1);
	new[0] = 0;
	ft_strcat(new, stock);
	ft_strcat(new, buf);
	return (new);
}

static char	*ft_word(char **str)
{
	int		i;
	char	*s;
	char	*line;

	s = *str;
	i = 0;
	while (s[i] != '\n' && s[i] != 0)
		i++;
	line = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i] != '\n' && s[i] != 0)
	{
		line[i] = s[i];
		i++;
	}
	*str = *str + i + 1;
	line[i] = '\0';
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str = "";
	char		buf[BUFF_SIZE + 1];
	int			i;

	if (fd < 0 || !line)
		return (-1);
	i = read(fd, buf, BUFF_SIZE);
	if (i == -1)
		return (-1);
	buf[i] = '\0';
	str = ft_new_malloc(str, buf, i);
	while (verif_end_of_file(str) == 0 && i != 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		i = read(fd, buf, BUFF_SIZE);
		buf[i] = '\0';
		str = ft_new_malloc(str, buf, i);
	}
	if (ft_strlen(str) == 0 && i <= BUFF_SIZE)
		return (0);
	*line = ft_word(&str);
	return (1);
}
