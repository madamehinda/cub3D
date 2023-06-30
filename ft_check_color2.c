/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:38:24 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 12:41:14 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_argcolor(char **str, t_data *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_check_color_arg(str[i], 'F') == 0 && j++ > -1)
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

int	just_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

//il faut free avant chaque msg err
int	ft_check_line_fd(char *str)
{
	int		i;
	char	**split;

	i = 0;
	split = NULL;
	split = ft_split(str, ' ');
	if (ft_strlen(split[0]) == 0)
		return (ft_free(split), 0);
	while (str[i])
	{
		if (ft_strlen_mat(split) < 1 || ft_strlen_mat(split) > INT_MAX)
			return (1);
		if (split[0][0] != 'N' && split[0][0] != 'S' && split[0][0] != 'W'
			&& split[0][0] != 'E' && split[0][0] != 'F' && split[0][0] != 'C'
			&& split[0][0] != '\n' && split[0][0] != '1' && split[0][0] != '0')
			return (ft_free(split), 1);
		i++;
	}
	ft_free(split);
	return (0);
}

//il faut free(tout les malloc avant chaque msg_err) avant chaque msg err
int	ft_check_fd(t_data *map)
{
	int	i;

	if (!map->tab_fd)
		return (1);
	i = 0;
	while (map->tab_fd[i])
	{
		if (ft_check_line_fd(map->tab_fd[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_tab_fd(t_data *map)
{
	int	i;

	i = 0;
	while (map->tab_fd[i])
	{
		if (ft_strchr(map->tab_fd[i], '\t'))
			return (1);
		i++;
	}
	return (0);
}
