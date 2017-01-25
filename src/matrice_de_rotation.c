/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_de_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:38:09 by lomeress          #+#    #+#             */
/*   Updated: 2017/01/24 19:33:22 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"
#include <math.h>

float	degree_to_radian(float deg)
{
	float rad;
	float pi;

	pi = 3.1415;
	rad = deg * (pi / 180);
	return (rad);
}

t_gen	malloco(int i, t_gen st)
{
	if (i == 0)
	{
		st.mt.xp = (float*)malloc(sizeof(float)
				* (st.reg.calx * st.reg.caly) + 1);
		st.mt.yp = (float*)malloc(sizeof(float)
				* (st.reg.calx * st.reg.caly) + 1);
		st.mt.zp = (float*)malloc(sizeof(float)
				* (st.reg.calx * st.reg.caly) + 1);
	}
	return (st);
}

void	trace_seg(t_gen st)
{
	int i;
	int s;

	i = -1;
	s = st.reg.calx - 1;
	while (++i - 1 < (st.reg.calx * st.reg.caly) - 1)
	{
		i == s + st.reg.caly ? s += st.reg.calx : (s += 0);
		if ((i <= (st.reg.calx * st.reg.caly) && i != s))
		{
			st.x1 = st.mt.xp[i] - st.gp.padx;
			st.y1 = st.mt.yp[i] - st.gp.pady;
			st.x2 = st.mt.xp[i + 1] - st.gp.padx;
			st.y2 = st.mt.yp[i + 1] - st.gp.pady;
			aff(st);
		}
		if (i <= (st.reg.calx * (st.reg.caly - 1)) - 1)
		{
			st.x1 = st.mt.xp[i] - st.gp.padx;
			st.y1 = st.mt.yp[i] - st.gp.pady;
			st.x2 = st.mt.xp[i + st.reg.calx] - st.gp.padx;
			st.y2 = st.mt.yp[i + st.reg.calx] - st.gp.pady;
			aff(st);
		}
	}
}

t_gen	transformers(t_gen st, float y, float x, float z)
{
	static int i = 0;

	st.mt.tmpx = x;
	st.mt.tmpy = y * cos(st.reg.rx) + z * -sin(st.reg.rx);
	st.mt.tmpz = y * sin(st.reg.rx) + z * cos(st.reg.rx);
	x = st.mt.tmpx * cos(st.reg.ry) + st.mt.tmpz * sin(st.reg.ry);
	y = st.mt.tmpy;
	z = st.mt.tmpx * -sin(st.reg.ry) + st.mt.tmpz * cos(st.reg.ry);
	st.mt.tmpx = x * cos(st.reg.rz) + y * -sin(st.reg.rz);
	st.mt.tmpy = x * sin(st.reg.rz) + y * cos(st.reg.rz);
	st.mt.tmpz = z;
	st.mt.ycop = ((float)st.mt.tmpy * st.gp.zoom + st.gp.pady);
	st.mt.xcop = ((float)st.mt.tmpx * st.gp.zoom + st.gp.padx);
	st.mt.zcop = ((float)st.mt.tmpz * st.gp.zoom + st.gp.padx);
	if (st.mt.ycop < -12000000 || st.mt.xcop < -12000000 ||
			st.mt.xcop > 12000000 || st.mt.ycop > 12000000)
		return (st);
	st = malloco(i, st);
	st.mt.xp[i] = st.mt.xcop;
	st.mt.yp[i] = st.mt.ycop;
	st.mt.zp[i] = st.mt.zcop;
	i++;
	if (i == (st.reg.calx * st.reg.caly))
		i = 0;
	return (st);
}

void	angle(t_gen st)
{
	int		i;
	int		a;

	i = 0;
	if ((st.reg.rx = degree_to_radian(st.mt.x)) == 360)
		st.reg.rx = 0;
	if ((st.reg.ry = degree_to_radian(st.mt.y)) == 360)
		st.reg.ry = 0;
	if ((st.reg.rz = degree_to_radian(st.mt.z)) == 360)
		st.reg.rz = 0;
	while (i < st.reg.caly)
	{
		a = 0;
		while (a < st.reg.calx)
		{
			st = transformers(st, i, a, st.pars.str[i][a]);
			a++;
		}
		i++;
	}
	trace_seg(st);
	mlx_put_image_to_window(st.mlx, st.win, st.img, 0, 0);
}
