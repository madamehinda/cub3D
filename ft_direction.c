/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:51:26 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/29 16:29:41 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//parser que chemin
void	ft_free_dir(t_data *map)
{
	if (map->north)
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->west)
		free(map->west);
	if (map->east)
		free(map->east);
}

void	check_dir(char *str, int *j, t_data *map)
{
	char	**split;

	split = ft_split(str, ' ');
	if (ft_strcmp(split[0], "NO") == 0 && ft_strlen(split[0]) == 2)
	{
		map->north = ft_strddup(split[1]);
		(*j)++;
	}
	if (ft_strcmp(split[0], "SO") == 0 && ft_strlen(split[0]) == 2)
	{
		map->south = ft_strddup(split[1]);
		(*j)++;
	}
	if (ft_strcmp(split[0], "WE") == 0 && ft_strlen(split[0]) == 2)
	{
		map->west = ft_strddup(split[1]);
		(*j)++;
	}
	if (ft_strcmp(split[0], "EA") == 0 && ft_strlen(split[0]) == 2)
	{
		map->east = ft_strddup(split[1]);
		(*j)++;
	}
	ft_free(split);
}

void close_fd(t_data *map)
{
	close(map->fdn);
	close(map->fds);
	close(map->fdw);
	close(map->fde);
}
int	ft_check_map_dir(char **str, t_data *map)
{
	// int	fdn;
	// int	fds;
	// int	fdw;
	// int	fde;

	if (ft_check_dir(str, map) == 2)
		return (2);
	map->fdn = open(map->north, O_RDONLY);
	map->fds = open(map->south, O_RDONLY);
	map->fde = open(map->east, O_RDONLY);
	map->fdw = open(map->west, O_RDONLY);
	if (map->fdn == -1 || map->fds == -1 || map->fde == -1 || map->fdw == -1)
		return (3);
	return (0);
}

int	ft_check_dir(char **str, t_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		check_dir(str[i], &j, map);
		i++;
	}
	if (j != 4)
		return (2);
	return (0);
}
