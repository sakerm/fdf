/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:53:10 by lomeress          #+#    #+#             */
/*   Updated: 2017/01/23 17:41:41 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include "mlx.h"

typedef struct		s_mlx
{
	int				padx;
	int				pady;
	float			zoom;
	char			*gda;
}					t_mlx;

typedef	struct		s_pars
{
	int				i;
	int				fd;
	int				x;
	int				y;
	int				**str;
	char			**val;
	char			**line;
	int				**tmp;
}					t_pars;

typedef struct		s_mt
{
	float			a;
	float			i;
	float			px;
	float			py;
	float			xcop;
	float			ycop;
	float			zcop;
	float			y;
	float			x;
	float			z;
	float			rx;
	float			ry;
	float			rz;
	float			*xp;
	float			*yp;
	float			*zp;
	float			tmpx;
	float			tmpy;
	float			tmpz;
	int				**tab;
}					t_mt;

typedef	struct		s_ev
{
	int				i;
	void			*mlx;
	void			*win;
}					t_ev;

typedef struct		s_reg
{
	int		calx;
	int		caly;
	int		color;
	float	rx;
	float	ry;
	float	rz;
	float	i;
	float	a;
	float	px;
	float	py;
}					t_reg;

typedef	struct		s_gen
{
	void			*mlx;
	void			*win;
	char			*img;
	int				bpx;
	int				size;
	int				end;
	int				dy;
	int				dx;
	int				e2;
	int				err;
	int				sx;
	int				sy;
	float			xcop;
	float			ycop;
	int				x;
	int				y;
	int				y1;
	int				x1;
	int				y2;
	int				x2;
	int				data;
	struct s_mlx	gp;
	struct s_pars	pars;
	struct s_mt		mt;
	struct s_ev		ev;
	struct s_reg	reg;
}					t_gen;

int					calcul_x(char *path);
int					calcul_y(char *path);
int					lenght(char *str);
t_gen				*int_read(t_gen *st, char **av);
void				aff(t_gen st);
void				angle(t_gen st);
int					my_key_funct(int i, void *param);
int					ex(void);
int					size_win(t_gen st, int i);

#endif
