/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulmet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:10:13 by atoulmet          #+#    #+#             */
/*   Updated: 2017/02/03 17:17:19 by atoulmet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		x_count(char *line)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 1)
			i++;
		else
		{
			while (line[i] && (ft_isspace(line[i]) != 1))
				i++;
			x++;
			if (line[i] == '\0')
				return (x);
		}
	}
	return (x);
}

void	check_file(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '-' || line[i] == '+') && ft_isdigit(line[i + 1]) == 0)
			fdf_error(MAP_ERROR);
		if (ft_isdigit(line[i]) == 0 && ft_isspace(line[i]) == 0
				&& (line[i] != '-' || line[i] == '+'))
			fdf_error(MAP_ERROR);
		i++;
	}
}
