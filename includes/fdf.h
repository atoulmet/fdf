/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 19:58:52 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/03 17:14:05 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define WIN_HEIGHT 1200
# define WIN_WIDTH 1200
# define RATIO_Z 2

typedef struct		s_env
{
	void	*window;
	void	*mlx;
}					t_env;

typedef struct		s_img
{
	void	*ptr;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		height;
	int		width;
	int		color;
}					t_img;

typedef struct		s_pt
{
	int x;
	int	y;
	int	z;
	int	xs;
	int ys;
}					t_pt;

typedef struct		s_linker
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e1;
	int		e2;

}					t_linker;

typedef struct		s_coord
{
	int		**tab;
	int		x_len;
	int		y_len;
	t_pt	p0;
	t_pt	pr;
	t_pt	pd;
	int		xs_min;
	int		xs_max;
	int		ys_min;
	int		ys_max;
}					t_coord;

enum
{
	ERR_MALLOC,
	GRAPHIC_FAILURE,
	OPEN_FILE_FAILURE,
	USAGE,
	MAP_ERROR
};

void				fdf_error(int flag);
t_coord				*parsing(char **av);
t_coord				*compute_screenview(t_coord *grid, t_env *e, t_img *img);
t_img				*put_pixel(t_img *img, int x, int y, t_env *e);
int					key_hook(int keycode, t_env *e);
void				link_points(t_pt p0, t_pt p1, t_img *img, t_env *e);
void				fdf(char **av);
void				resize(int *xs, int *ys, t_coord *grid);
int					x_count(char *line);
void				check_file(char *line);

#endif
