/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:29:01 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/03 17:17:46 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		measure(t_coord *grid)
{
	int i;
	int j;
	int xs;
	int ys;

	j = 0;
	while (j < grid->y_len)
	{
		i = 0;
		while (i < grid->x_len)
		{
			xs = i - j;
			ys = i + j - (grid->tab[j][i]);
			grid->xs_min = xs < grid->xs_min ? xs : grid->xs_min;
			grid->ys_min = ys < grid->ys_min ? ys : grid->ys_min;
			grid->xs_max = xs > grid->xs_max ? xs : grid->xs_max;
			grid->ys_max = ys > grid->ys_max ? ys : grid->ys_max;
			i++;
		}
		j++;
	}
}

void			resize(int *xs, int *ys, t_coord *grid)
{
	measure(grid);
	*xs = ((*xs - grid->xs_min)) * 800 / (grid->xs_max - grid->xs_min);
	*ys = ((*ys - grid->ys_min)) * 800 / (grid->ys_max - grid->ys_min);
}
