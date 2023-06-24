/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:50:35 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/20 14:50:36 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_in_color_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i != 0)
		{
			if (str[i] != ' ' && str[i] != ',' && str[i] != '\n'
				&& ft_isdigit(str[i]) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

//tableax rgb F et C
//fct ft_atoii fct changee dans la libft
int	parse_rgb(t_data *map, char **tmp, char c)
{
	int	i;

	i = 0;
	while (i < 3 && c == 'C')
	{
		if (ft_atoii(tmp[i]) == -1)
			return (1);
		map->c_rgb[i] = ft_atoii(tmp[i]);
		i++;
	}
	i = 0;
	while (i < 3 && c == 'F')
	{
		if (ft_atoii(tmp[i]) == -1)
			return (1);
		printf("I = %d et tmp[i] = %s\n", i, tmp[i]);
		map->f_rgb[i] = ft_atoii(tmp[i]);
		printf("map->f_rgb[%d] = %d\n", i, map->f_rgb[i]);
		i++;
	}
	return (0);
}
int	util_check_color_format(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && (ft_isdigit(str[i + 1]) != 0 || ft_isdigit(str[i
					- 1] != 0)))
			j++;
		i++;
	}
	if (j != 2)
		return (1);
	return (0);
}
int	check_color_format(char *str, char c, t_data *map)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	if (util_check_color_format(str))
		return (1);
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != '\0' && i++ > -1)
		{
			tmp = ft_split(str + i, ',');
			break ;
		}
		i++;
	}
	if (ft_strlen_mat(tmp) != 3 || parse_rgb(map, tmp, c) == 1)
		return (ft_free(tmp), 1);
	return (ft_free(tmp), 0);
}

int	ft_check_color_arg(char *str, char c)
{
	char	**tmp;

	tmp = NULL;
	if (str[0] != c)
		return (1);
	check_in_color_arg(str);
	tmp = ft_split(str, ' ');
	if (ft_strlen_mat(tmp) != 2 || ft_strlen(tmp[0]) != 1)
		return (ft_free(tmp), 2);
	ft_free(tmp);
	return (0);
}

int	ft_check_argcolor(char **str, t_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_check_color_arg(str[i], 'F') == 0 && j++ > -1)
			//pour gagner une ligne et avancer mon j
			map->f = str[i];
		if (ft_check_color_arg(str[i], 'C') == 0 && j++ > -1)
			map->c = str[i];
		i++;
	}
	if (j != 2)
		return (3);
	j = check_color_format(map->f, 'F', map);
	j = j + check_color_format(map->c, 'C', map);
	if (j != 0)
		return (4);
	return (0);
}
