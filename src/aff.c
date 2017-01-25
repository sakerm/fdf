/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:34:14 by lomeress          #+#    #+#             */
/*   Updated: 2017/01/24 19:37:39 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"

int		color(t_gen st)
{
	if (st.reg.color == 1)
		return (0xFF6666);
	if (st.reg.color == 2)
		return (0x9999FF);
	if (st.reg.color == 3)
		return (0x9933CC);
	if (st.reg.color == 4)
		return (0x009900);
	if (st.reg.color == 5)
		return (0xCC0000);
	if (st.reg.color == 6)
		return (0x663300);
	return (0xffffff);
}

int		abso(t_gen st, int i)
{
	if (i == 0)
	{
		if (st.x2 - st.x1 < 0)
		{
			return ((st.x2 - st.x1) * (-1));
		}
		return (st.x2 - st.x1);
	}
	if (st.y2 - st.y1 < 0)
	{
		return ((st.y2 - st.y1) * (-1));
	}
	return (st.y2 - st.y1);
}

void	dep(t_gen st)
{
	if (st.gp.padx + st.x1 < size_win(st, 1) && st.gp.padx + st.x1 > 0 &&
			st.gp.pady + st.y1 < size_win(st, 1) && st.gp.pady + st.y1 > 0)
	{
		st.ycop = (st.y1 + st.gp.pady) * st.size;
		st.xcop = (st.x1 + st.gp.padx) * st.bpx / 8;
		*(unsigned*)(st.gp.gda + (int)st.xcop + (int)st.ycop) = color(st);
	}
}

void	aff(t_gen st)
{
	st.sx = st.x1 < st.x2 ? 1 : -1;
	st.sy = st.y1 < st.y2 ? 1 : -1;
	st.dx = abso(st, 0);
	st.dy = abso(st, 1);
	st.err = (st.dx > st.dy ? st.dx : -st.dy) / 2;
	while (1)
	{
		dep(st);
		if (st.x1 == st.x2 && st.y1 == st.y2)
			break ;
		st.e2 = st.err;
		if (st.e2 > -st.dx)
		{
			st.err -= st.dy;
			st.x1 += st.sx;
		}
		if (st.e2 < st.dy)
		{
			st.err += st.dx;
			st.y1 += st.sy;
		}
	}
}
