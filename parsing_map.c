/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:54:25 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 14:54:12 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dir(t_data *map)
{
	map->n = 0;
	map->s = 0;
	map->w = 0;
	map->e = 0;
}

int	ft_check_parse_dir(t_data *map)
{
	char	**split;
	int		i;

	i = 0;
	init_dir(map);
	while (map->tab_fd[i])
	{
		split = ft_split(map->tab_fd[i], ' ');
		if (ft_strcmp(split[0], "NO") == 0)
			map->n++;
		if (ft_strcmp(split[0], "SO") == 0)
			map->s++;
		if (ft_strcmp(split[0], "WE") == 0)
			map->w++;
		if (ft_strcmp(split[0], "EA") == 0)
			map->e++;
		ft_free(split);
		if (map->n == 1 && map->s == 1 && map->w == 1 && map->e == 1)
			return (0);
		i++;
	}
	if (map->n != 1 && map->s != 1 && map->w != 1 && map->e != 1)
		return (1);
	return (0);
}

int	ft_check_parse_rgb(char **str)
{
	char	**split;
	int		c;
	int		f;
	int		i;

	c = 0;
	f = 0;
	i = 0;
	while (str[i])
	{
		split = ft_split(str[i], ' ');
		if (split && split[0] && ft_strcmp(split[0], "C") == 0)
			c++;
		if (split && split[0] && ft_strcmp(split[0], "F") == 0)
			f++;
		ft_free(split);
		i++;
	}
	if (c == 1 && f == 1)
		return (0);
	else
		return (1);
	return (0);
}

void	count_ligne_valid(char *str, int *j, int *i)
{
	char	**split;

	split = ft_split(str, ' ');
	if (ft_strcmp(split[0], "NO") == 0)
		(*j)++;
	if (ft_strcmp(split[0], "\n") == 0)
		(*i)++;
	if (ft_strcmp(split[0], "SO") == 0)
		(*j)++;
	if (ft_strcmp(split[0], "WE") == 0)
		(*j)++;
	if (ft_strcmp(split[0], "EA") == 0)
		(*j)++;
	if (ft_strcmp(split[0], "C") == 0)
		(*j)++;
	if (ft_strcmp(split[0], "F") == 0)
		(*j)++;
	ft_free(split);
}

int	ft_check_map_fd(t_data *map, char **str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[k] && j <= 5)
	{
		count_ligne_valid(str[k], &j, &i);
		k++;
	}
	map->begin = i + j;
	if (j != 6)
		return (1);
	if (map->begin != k)
		return (1);
	return (0);
}
