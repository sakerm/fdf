/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:48:39 by lomeress          #+#    #+#             */
/*   Updated: 2017/01/24 19:46:30 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/struct.h"

int		size_win(t_gen st, int i)
{
	if (i == 1)
	{
		if ((st.reg.calx * st.reg.caly) < 400)
			return (600);
		if ((st.reg.calx * st.reg.caly) < 800)
			return (800);
		else
			return (1200);
	}
	if (i == 2)
	{
		if ((st.reg.calx * st.reg.caly) < 400)
			return (7);
		if ((st.reg.calx * st.reg.caly) < 115800)
			return (3);
		else
			return (1);
	}
	return (0);
}

void	event(int kc, t_gen *st)
{
	int		i;
	float	ang;

	i = 10;
	ang = 5;
	kc == 88 ? st->gp.padx += i++ : i == 0;
	kc == 86 ? st->gp.padx -= i-- : i == 0;
	kc == 84 ? st->gp.pady += i++ : i == 0;
	kc == 91 ? st->gp.pady -= i-- : i == 0;
	kc == 126 ? st->mt.x += ang : i == 0;
	kc == 125 ? st->mt.x -= ang : i == 0;
	kc == 123 ? st->mt.y -= ang : i == 0;
	kc == 124 ? st->mt.y += ang : i == 0;
	kc == 69 ? st->gp.zoom += 0.25 : i == 0;
	kc == 78 ? st->gp.zoom -= 0.25 : i == 0;
	kc == 18 ? st->reg.color = 1 : i == 0;
	kc == 19 ? st->reg.color = 2 : i == 0;
	kc == 20 ? st->reg.color = 3 : i == 0;
	kc == 21 ? st->reg.color = 4 : i == 0;
	kc == 22 ? st->reg.color = 5 : i == 0;
	kc == 23 ? st->reg.color = 6 : i == 0;
	kc == 29 ? st->reg.color = 0 : i == 0;
	kc == 53 ? exit(1) : i == 0;
}

int		my_key_funct(int kc, void *param)
{
	t_gen	*st;

	st = (t_gen*)param;
	ft_putnbr(kc);
	mlx_destroy_image(st->mlx, st->img);
	st->img = mlx_new_image(st->mlx, size_win(*st, 1), size_win(*st, 1));
	st->gp.gda = mlx_get_data_addr(st->img, &st->bpx, &st->size, &st->end);
	event(kc, st);
	angle(*st);
	return (0);
}

int		main(int argc, char **argv)
{
	t_gen	st;

	if (argc != 2 || open(argv[1], O_RDONLY) == -1)
	{
		ft_putstr("error");
		return (0);
	}
	st.mlx = mlx_init();
	st = *int_read(&st, argv);
	st.win = mlx_new_window(st.mlx, size_win(st, 1), size_win(st, 1), "mlx42");
	st.img = mlx_new_image(st.mlx, size_win(st, 1), size_win(st, 1));
	st.gp.gda = mlx_get_data_addr(st.img, &st.bpx, &st.size, &st.end);
	mlx_key_hook(st.win, my_key_funct, &st);
	st.gp.padx = size_win(st, 1) / 2;
	st.gp.pady = size_win(st, 1) / 2;
	st.gp.zoom = size_win(st, 2);
	st.mt.x = 70;
	st.mt.y = 10;
	angle(st);
	mlx_loop(st.mlx);
	free(st.pars.str);
	return (0);
}
