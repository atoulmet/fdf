/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:33:10 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/03 17:16:40 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord		*xy_count_and_check(int fd, t_coord *grid)
{
	char	*line;
	int		y_len;
	int		x_len;

	y_len = 0;
	x_len = 0;
	while (get_next_line(fd, &line) == 1)
	{
		check_file(line);
		x_len = x_count(line);
		y_len++;
	}
	grid->x_len = x_len;
	grid->y_len = y_len;
	close(fd);
	return (grid);
}

static int			*fill(char *line, t_coord *grid)
{
	int		i;
	int		*tab_line;
	int		x;

	i = 0;
	x = 0;
	tab_line = (int*)ft_memalloc(sizeof(int) * grid->x_len);
	while (line[i])
	{
		if (line[i] == '-' || line[i] == '+' || (ft_isdigit(line[i]) == 1))
		{
			tab_line[x] = ft_atoi(line + i);
			x++;
			while (line[i] == '-' || line[i] == '+' || ft_isdigit(line[i]) == 1)
				i++;
		}
		else
			i++;
	}
	return (tab_line);
}

static int			**alloc_x_and_fill(int fd, int **tab, t_coord *grid)
{
	int		y;
	char	*line;

	y = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((tab[y] = ft_memalloc(sizeof(int) * (grid->x_len))) == 0)
			fdf_error(ERR_MALLOC);
		tab[y] = fill(line, grid);
		y++;
	}
	return (tab);
}

t_coord				*parsing(char **av)
{
	int		fd;
	t_coord	*grid;

	if ((grid = (t_coord*)ft_memalloc(sizeof(t_coord))) == NULL)
		fdf_error(ERR_MALLOC);
	if ((fd = open(av[1], O_RDONLY)) == 0)
		fdf_error(OPEN_FILE_FAILURE);
	grid = xy_count_and_check(fd, grid);
	if ((grid->tab = ft_memalloc(sizeof(char **) * grid->y_len)) == 0)
		fdf_error(ERR_MALLOC);
	if ((fd = open(av[1], O_RDONLY)) == 0)
		fdf_error(OPEN_FILE_FAILURE);
	grid->tab = alloc_x_and_fill(fd, grid->tab, grid);
	return (grid);
}
