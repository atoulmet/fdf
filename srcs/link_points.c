/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:42:38 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/03 12:08:31 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_linker(t_pt p0, t_pt p1, t_linker *l)
{
	l->dx = abs(p1.xs - p0.xs);
	l->dy = abs(p1.ys - p0.ys);
	l->sx = p0.xs < p1.xs ? 1 : -1;
	l->sy = p0.ys < p1.ys ? 1 : -1;
	l->e1 = (l->dx > l->dy ? l->dx : -(l->dy)) / 2;
	l->x = p0.xs;
	l->y = p0.ys;
}

void		link_points(t_pt p0, t_pt p1, t_img *img, t_env *e)
{
	t_linker l;

	init_linker(p0, p1, &l);
	while (l.x != p1.xs || l.y != p1.ys)
	{
		put_pixel(img, l.x, l.y, e);
		l.e2 = l.e1;
		if (l.e2 > -l.dx)
		{
			l.e1 -= l.dy;
			l.x += l.sx;
		}
		if (l.e2 < l.dy)
		{
			l.e1 += l.dx;
			l.y += l.sy;
		}
	}
}
