/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:49:19 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/29 20:19:59 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_parsing_fd(t_data *map, char **argv)
{
	map->fdn = 0;
	map->fds = 0;
	map->fde = 0;
	map->fdw = 0;
	map->nbr_line = count_lines(argv[1]);
	if (!map->nbr_line)
		return (destroy_mlx(map), close_fd(map),msg_err("File map is too big for int parsing ", argv[1]), 1);
	if (map->nbr_line < 5)
		return (destroy_mlx(map), close_fd(map), msg_err("Not enough informations to start ", argv[1]), 1);
	get_fd(argv, map, map->nbr_line);
	if (ft_check_tab_fd(map))
		return (destroy_mlx(map), close_fd(map), msg_err("tab in fd ", argv[1]), 1);
	if (ft_check_parse_dir(map->tab_fd) != 0)
		return (destroy_mlx(map), close_fd(map), msg_err("parse direction ", argv[1]), 1);
	if (ft_check_parse_rgb(map->tab_fd))
		return (destroy_mlx(map), close_fd(map), msg_err("parse rgb  ", argv[1]), 1);
	if (ft_check_map_fd(map, map->tab_fd))
		return (destroy_mlx(map), close_fd(map), msg_err("count line dir rgb  ", argv[1]), 1);
	if (ft_check_fd(map))
		return (destroy_mlx(map),close_fd(map),  msg_err("invalid character in map ", argv[1]), 1);
	ft_parsing_fd2(map, argv);
	return (0);
}

int	ft_parsing_fd2(t_data *map, char **argv)
{
	if (ft_check_map_dir(map->tab_fd, map))
		return (destroy_mlx(map),close_fd(map),
			msg_err("error parse direction or error texture path", argv[1]), 1);
	if (ft_check_argcolor(map->tab_fd, map))
		return (destroy_mlx(map),close_fd(map), msg_err("error parse color  ", argv[1]), 1);
	if (parse_map(map))
		return (destroy_mlx(map),close_fd(map), msg_err("error parse map ", argv[1]));
	if (ft_check_symbol(map))
		return (destroy_mlx(map),close_fd(map), msg_err("error symbol map ", argv[1]));
	if (ft_check_carte_line_empty(map))
		return (destroy_mlx(map), close_fd(map),msg_err("map ligne dans map ", argv[1]));
	if (check_player(map))
		return (destroy_mlx(map),close_fd(map),
			msg_err("multiple player or no player or unclosed or space in map", argv[1]));
	close_fd(map);
	return (0);
}

// Obtenir addr textures
void	ft_textures_addr(t_data *game)
{
	game->texture[0].addr = (int *)mlx_get_data_addr(game->texture[0].img,
			&game->texture[0].bits_per_pixel, &game->texture[0].line_length,
			&game->texture[0].endian);
	game->texture[1].addr = (int *)mlx_get_data_addr(game->texture[1].img,
			&game->texture[1].bits_per_pixel, &game->texture[1].line_length,
			&game->texture[1].endian);
	game->texture[2].addr = (int *)mlx_get_data_addr(game->texture[2].img,
			&game->texture[2].bits_per_pixel, &game->texture[2].line_length,
			&game->texture[2].endian);
	game->texture[3].addr = (int *)mlx_get_data_addr(game->texture[3].img,
			&game->texture[3].bits_per_pixel, &game->texture[3].line_length,
			&game->texture[3].endian);
}

// Chargement des textures
void	ft_textures(t_data *game)
{
	
	game->texture[0].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->north, &game->texture[0].width, &game->texture[0].height);
	if (!game->texture[0].img)
	{
		printf("Error\nTexture not found");
		exit_game(game);
	}
	game->texture[1].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->south, &game->texture[1].width, &game->texture[1].height);
	if (!game->texture[1].img)
	{
		printf("Error\nTexture not found");
		exit_game(game);
	}
	game->texture[2].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->west, &game->texture[2].width, &game->texture[2].height);
	if (!game->texture[2].img)
	{
		printf("Error\nTexture not found");
		exit_game(game);
	}
	game->texture[3].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->east, &game->texture[3].width, &game->texture[3].height);
	if (!game->texture[3].img)
	{
		printf("Error\nTexture not found");
		exit_game(game);
	}
	ft_textures_addr(game);
}

int	ft_mlx(t_data *game)
{
	mlx_hook(game->mlx.mlx_win, 2, 1L << 0, &ft_press, game);
	mlx_hook(game->mlx.mlx_win, DestroyNotify, StructureNotifyMask, &exit_game, game);
	mlx_loop_hook(game->mlx.mlx_ptr, &ft_raycasting, game);
	mlx_hook(game->mlx.mlx_win, 3, 1L << 1, &ft_release, game);
	mlx_loop(game->mlx.mlx_ptr);
	return (0);
}


int main(int argc,char **argv, char **env)
{
	t_data data;
	
	if (!env[0])
		return(ft_putstr_fd("no env\n", 2),0);
	if (ft_strcmp("USER=hferjani", env[0]) != 0)
		return(ft_putstr_fd("no env\n", 2),0);
	setup_game(&data);
	if(argc==2)
	{
		if(!ft_check_cub(argv[1]))
			return(msg_err("error extention .cub ",argv[1]));
		ft_parsing_fd(&data,argv);
		if (ft_initialise_and_create_window(&data))
		{
			ft_mlx(&data);
		}
		destroy_mlx(&data);
    }
	return(0);
}
