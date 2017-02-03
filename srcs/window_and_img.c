/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:13:53 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/03 17:20:07 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env		*env_init(t_env *e)
{
	if ((e = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
		fdf_error(ERR_MALLOC);
	if ((e->mlx = mlx_init()) == NULL)
		fdf_error(GRAPHIC_FAILURE);
	if ((e->window = mlx_new_window(e->mlx, WIN_WIDTH,
					WIN_HEIGHT, "fdf")) == NULL)
		fdf_error(GRAPHIC_FAILURE);
	return (e);
}

t_img		*init_img(t_env *e, t_img *img)
{
	if ((img = (t_img*)ft_memalloc(sizeof(t_img))) == NULL)
		fdf_error(ERR_MALLOC);
	img->height = WIN_HEIGHT;
	img->width = WIN_WIDTH;
	if ((img->ptr = mlx_new_image(e->mlx, img->width, img->height)) == NULL)
		fdf_error(GRAPHIC_FAILURE);
	return (img);
}

t_img		*put_pixel(t_img *img, int x, int y, t_env *e)
{
	int		index;
	int		i;

	i = 0;
	img->color = mlx_get_color_value(e->mlx, 0X00FFFFFF);
	index = y * img->size_line + x * (img->bits_per_pixel / 8);
	while (i < (img->bits_per_pixel / 8))
	{
		img->data_addr[index + i] = *((char*)&(img->color) + i);
		i++;
	}
	return (img);
}

void		fdf(char **av)
{
	t_coord		*grid;
	t_env		*e;
	t_img		*img;

	e = NULL;
	img = NULL;
	grid = parsing(av);
	e = env_init(e);
	img = init_img(e, img);
	img->data_addr = mlx_get_data_addr(img->ptr, &(img->bits_per_pixel),
			&(img->size_line), &(img->endian));
	grid = compute_screenview(grid, e, img);
	mlx_put_image_to_window(e->mlx, e->window, img->ptr, 100, 100);
	mlx_key_hook(e->window, key_hook, &e);
	mlx_loop(e->mlx);
}
