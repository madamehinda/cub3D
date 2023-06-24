/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:51:26 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/20 14:53:51 by hferjani         ###   ########.fr       */
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

int	ft_check_map_dir(char **str, t_data *map)
{
	int	i;
	int	j;
	int	fdN;
	int	fdS;
	int	fdW;
	int	fdE;

	i = 0;
	j = 0;
	while (str[i])
	{
		check_dir(str[i], &j, map);
		i++;
	}
	if (j != 4)
		return (2);
	fdN = open(map->north, O_RDONLY);
	fdS = open(map->south, O_RDONLY);
	fdE = open(map->east, O_RDONLY);
	fdW = open(map->west, O_RDONLY);
	if (fdN == -1 || fdS == -1 || fdE == -1 || fdW == -1)
		return (3);
	return (0);
}
