/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_screen_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:19:48 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/03 17:07:02 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_p0(int i, int j, t_coord *grid)
{
	int		xs;
	int		ys;

	grid->p0.z = grid->tab[j][i];
	xs = (i - j);
	ys = ((i + j - (grid->p0.z) / RATIO_Z));
	resize(&xs, &ys, grid);
	grid->p0.ys = ys;
	grid->p0.xs = xs;
}

static void		init_pr(int i, int j, t_coord *grid)
{
	int		xs;
	int		ys;

	grid->pr.z = grid->tab[j][i + 1];
	xs = ((i + 1) - j);
	ys = ((i + 1) + j - (grid->pr.z / RATIO_Z));
	resize(&xs, &ys, grid);
	grid->pr.ys = ys;
	grid->pr.xs = xs;
}

static void		init_pd(int i, int j, t_coord *grid)
{
	int		xs;
	int		ys;

	grid->pd.z = grid->tab[j + 1][i];
	xs = (i - (j + 1));
	ys = (i + (j + 1) - ((grid->pd.z) / RATIO_Z));
	resize(&xs, &ys, grid);
	grid->pd.ys = ys;
	grid->pd.xs = xs;
}

t_coord			*compute_screenview(t_coord *grid, t_env *e, t_img *img)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	while (++j < grid->y_len)
	{
		i = -1;
		while (++i < grid->x_len)
		{
			init_p0(i, j, grid);
			put_pixel(img, grid->p0.xs, grid->p0.ys, e);
			if (i < (grid->x_len - 1))
			{
				init_pr(i, j, grid);
				link_points(grid->p0, grid->pr, img, e);
			}
			if (j < (grid->y_len - 1))
			{
				init_pd(i, j, grid);
				link_points(grid->p0, grid->pd, img, e);
			}
		}
	}
	return (grid);
}

int				key_hook(int keycode, t_env *e)
{
	t_env	*tg;

	tg = e;
	if (keycode == 53)
		exit(1);
	return (0);
}
