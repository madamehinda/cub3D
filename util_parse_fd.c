/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:56:54 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 13:53:57 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//calculer nbr ligne map
long int	count_lines(char *argv)
{
	int			fd;
	long int	i;
	char		*line;

	line = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		msg_err("Invalid file", NULL);
	i = 0;
	line = get_next_line(fd);
	if (!line)
		msg_err("empty map ", NULL);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	if (i > 2147483647)
		return (0);
	return (i);
}

//malloc mon tab_fd(tout file)
void	get_fd(char **argv, t_data *map, long int size)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		msg_err("Invalid file", argv[1]);
	map->tab_fd = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map->tab_fd)
		return ;
	map->tab_fd[i] = get_next_line(fd);
	while (map->tab_fd[i])
	{
		i++;
		map->tab_fd[i] = get_next_line(fd);
	}
	fd = close(fd);
	map->tab_fd[i] = NULL;
}

//il faut faire la fct qui destroy mlx(free_mlx)
void	destroy_mlx(t_data *map)
{
	if (map->tab_fd)
		ft_free(map->tab_fd);
	if (map->tab)
		ft_free(map->tab);
	if (map->dup)
		ft_free(map->dup);
	ft_free_dir(map);
}
