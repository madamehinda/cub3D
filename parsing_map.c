/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:54:25 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/29 16:50:56 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dir(int *n, int *s, int *w, int *e)
{
	(*n) = 0;
	(*s) = 0;
	(*w) = 0;
	(*e) = 0;
}
int	ft_check_parse_dir(char **str)
{
	char	**split;
	int		n;
	int		s;
	int		w;
	int		e;
	int		i;

	i = 0;
	init_dir(&n, &s, &w, &e);
	while (str[i])
	{
		split = ft_split(str[i], ' ');
		if (ft_strcmp(split[0], "NO") == 0)
			n++;
		if (ft_strcmp(split[0], "SO") == 0)
			s++;
		if (ft_strcmp(split[0], "WE") == 0)
			w++;
		if (ft_strcmp(split[0], "EA") == 0)
			e++;
		ft_free(split);
		i++;
	}
	if (n == 1 && s == 1 && w == 1 && e == 1)
		return (0);
	else
		return (1);
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
		if (ft_strcmp(split[0], "C") == 0)
			c++;
		if (ft_strcmp(split[0], "F") == 0)
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
	
	if (!str || !str[0])
		return (1);
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
	//printf("%s\n", str[k]);
	return (0);
}

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
		map->direction.N = 1;
	if (map->tab[i][j] == 'E')
		map->direction.E = 1;
	if (map->tab[i][j] == 'W')
		map->direction.W = 1;
	if (map->tab[i][j] == 'S')
		map->direction.S = 1;
}

int	check_player(t_data *map)
{
	//int	j;

//	j = 0;
	if (ft_check_nbr_player(map->tab))
		return (1);
	if (pos_player(map->tab, map))
		return (2);
	// printf("pos_x%d\n", map->pos_x);
	// printf("pos_y%d\n", map->pos_y);
	ft_parse_player(map);
	if (ft_dup(map))
		return (3);
	// printf("\n******tableau dup******\n");
	// while (map->dup[j])
	// {
	// 	printf("%s", map->dup[j]);
	// 	j++;
	// }
	//printf("\n");
	return (0);
}
