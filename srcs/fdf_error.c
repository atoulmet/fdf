/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:16:34 by atoulmet          #+#    #+#             */
/*   Updated: 2017/01/31 18:41:30 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_error(int flag)
{
	if (flag == ERR_MALLOC)
	{
		ft_putendl("Malloc erro");
		exit(0);
	}
	if (flag == OPEN_FILE_FAILURE)
	{
		ft_putendl("Open file fail");
		exit(0);
	}
	if (flag == GRAPHIC_FAILURE)
	{
		ft_putendl("Graphic Fail");
		exit(0);
	}
	if (flag == USAGE)
	{
		ft_putendl("Usage error");
		exit(0);
	}
	if (flag == MAP_ERROR)
	{
		ft_putendl("Map Error");
		exit(0);
	}
}
