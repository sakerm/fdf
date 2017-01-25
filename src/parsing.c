/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:21:28 by lomeress          #+#    #+#             */
/*   Updated: 2017/01/25 14:48:32 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"

int		calcul_y(char *path)
{
	char		*line;
	int			y;
	int			fd;

	y = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
		y++;
	return (y);
}

int		calcul_x(char *path)
{
	char		**tab;
	int			x;
	char		*line;
	int			fd;

	x = 0;
	fd = open(path, O_RDONLY);
	get_next_line(fd, &line);
	if (line)
	{
		tab = ft_strsplit(line, ' ');
		while (tab[x])
			x++;
	}
	return (x);
}

int		lenght(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

t_gen	*mallococo(t_gen *st)
{
	if ((st->pars.str = (int**)malloc(sizeof(int*)
					* (st->reg.caly + 1))) == NULL)
		return (NULL);
	while (--st->pars.i)
		if ((st->pars.str[st->pars.i - 1] = (int*)malloc(sizeof(int)
						* st->reg.calx + 1)) == NULL)
			return (NULL);
	return (st);
}

t_gen	*int_read(t_gen *st, char **av)
{
	int w;
	int y;

	st->reg.caly = calcul_y(av[1]);
	st->reg.calx = calcul_x(av[1]);
	st->pars.i = st->reg.calx + 1;
	st = mallococo(st);
	st->pars.fd = open(av[1], O_RDONLY);
	st->pars.i = -1;
	while (++st->pars.i < st->reg.caly)
	{
		get_next_line(st->pars.fd, av);
		w = 0;
		y = 0;
		while (y < st->reg.calx)
		{
			st->pars.str[st->pars.i][y++] = ft_atoi_ch(&av[0][w]);
			w += lenght(&av[0][w]);
		}
	}
	st->pars.str[st->pars.i] = NULL;
	close(st->pars.fd);
	return (st);
}
