/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:31:06 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 14:57:12 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_carte_line_empty(t_data *map)
{
	int	i;

	i = 0;
	while (map->tab[i])
	{
		if (ft_check_line_empty(map->tab[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_nbr_player(char **str)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'S' || str[i][j] == 'E'
				|| str[i][j] == 'W')
				nb++;
			j++;
		}
		i++;
	}
	if (nb == 1)
		return (0);
	else
		return (1);
}

int	pos_player(char **str, t_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'S' || str[i][j] == 'E'
				|| str[i][j] == 'W')
			{
				map->pos_x = i;
				map->pos_y = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_parse_player(t_data *map)
{
	int	i;
	int	j;

	ft_init_pos(map);
	i = map->pos_x;
	j = map->pos_y;
	if (map->tab[i][j] == 'N')
		map->direction.n = 1;
	if (map->tab[i][j] == 'E')
		map->direction.e = 1;
	if (map->tab[i][j] == 'W')
		map->direction.w = 1;
	if (map->tab[i][j] == 'S')
		map->direction.s = 1;
}

int	check_player(t_data *map)
{
	if (ft_check_nbr_player(map->tab))
		return (1);
	if (pos_player(map->tab, map))
		return (2);
	ft_parse_player(map);
	if (ft_dup(map))
		return (3);
	return (0);
}
