/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:35:51 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 14:36:27 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_line_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'E' || str[i] == 'W')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_symbol(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] != ' ' && map->tab[i][j] != 'N'
				&& map->tab[i][j] != 'S' && map->tab[i][j] != 'E'
				&& map->tab[i][j] != 'W' && map->tab[i][j] != '\n'
				&& map->tab[i][j] != '\0' && map->tab[i][j] != '1'
				&& map->tab[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_map(t_data *map)
{
	int	i;
	int	j;

	j = 0;
	i = map->begin;
	while (map->tab_fd[i] && ft_check_line_empty(map->tab_fd[i]))
		i++;
	map->nbr_line--;
	while (map->tab_fd[map->nbr_line]
		&& ft_check_line_empty(map->tab_fd[map->nbr_line]))
		map->nbr_line--;
	map->nbr_line++;
	map->tab = malloc(sizeof(char *) * (map->nbr_line - i + 1));
	if (!map->tab)
		return (1);
	while (i < map->nbr_line)
	{
		map->tab[j] = ft_strdup(map->tab_fd[i]);
		i++;
		j++;
	}
	map->height = j;
	map->tab[j] = '\0';
	return (0);
}
