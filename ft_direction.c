/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:51:26 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 12:53:51 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_dir(char *str, int *j, t_data *map)
{
	char	**split;

	split = ft_split(str, ' ');
	if (split[0] && ft_strcmp(split[0], "NO") == 0 && ft_strlen(split[0]) == 2)
	{
		if (map->north)
			free(map->north);
		map->north = ft_strddup(split[1]);
		(*j)++;
	}
	if (split[0] && ft_strcmp(split[0], "SO") == 0 && ft_strlen(split[0]) == 2)
	{
		if (map->south)
			free(map->south);
		map->south = ft_strddup(split[1]);
		(*j)++;
	}
	check_dir2(split, j, map);
}

void	check_dir2(char **split, int *j, t_data *map)
{
	if (split[0] && ft_strcmp(split[0], "WE") == 0 && ft_strlen(split[0]) == 2)
	{
		if (map->west)
			free(map->west);
		map->west = ft_strddup(split[1]);
		(*j)++;
	}
	if (split[0] && ft_strcmp(split[0], "EA") == 0 && ft_strlen(split[0]) == 2)
	{
		if (map->east)
			free(map->east);
		map->east = ft_strddup(split[1]);
		(*j)++;
	}
	ft_free(split);
}

void	close_fd(t_data *map)
{
	if (map->fdn > 2)
		close(map->fdn);
	if (map->fds > 2)
		close(map->fds);
	if (map->fde > 2)
		close(map->fdw);
	if (map->fdw > 2)
		close(map->fde);
}

int	ft_check_map_dir(char **str, t_data *map)
{
	if (ft_check_dir(str, map) == 2)
		return (2);
	if (map->north == NULL || map->south == NULL || map->west == NULL
		|| map->east == NULL)
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
