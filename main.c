/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:49:19 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/24 18:31:14 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


//il faut free avant chaque msg err
int	ft_check_line_fd(char *str)
{
	int			i;
	char		**split;

	i = 0;
	split = NULL;

	while (str[i])
	{
		split = ft_split(str, ' ');
		if (ft_strlen_mat(split) < 1 || ft_strlen_mat(split) > INT_MAX)
			return (1);
		if (split[0][0] != 'N' && split[0][0] != 'S' && split[0][0] != 'W' 
		&& split[0][0] != 'E' && split[0][0] != 'F' 
		&& split[0][0] != 'C' && split[0][0] != '\n' && split[0][0] != '1' 
		&& split[0][0] != '0')
			return (ft_free(split), 1);
		ft_free(split);
		i++;
	}
	/*if(i < 6)
		return (1);*/
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
			return(1);
		i++;
	}
	return (0);
}

int ft_parsing_fd(t_data *map,char **argv)
{
	
	map->nbr_line = count_lines(argv[1]);
	if (!map->nbr_line)
		return (destroy_mlx(map),msg_err("File map is too big for int parsing ", argv[1]),1);
	if (map->nbr_line < 5)
		return (destroy_mlx(map),msg_err("Not enough informations to start ", argv[1]),1);
	get_fd( argv ,map,map->nbr_line);
	if(ft_check_parse_dir(map->tab_fd) != 0)
		return (destroy_mlx(map),msg_err("parse direction ", argv[1]),1);
	if(ft_check_parse_rgb(map->tab_fd))
		return (destroy_mlx(map),msg_err("parse rgb  ", argv[1]),1);
	if(ft_check_map_fd(map,map->tab_fd))
		return (destroy_mlx(map),msg_err("count line dir rgb  ", argv[1]),1);
	if(ft_check_fd(map))
		return (destroy_mlx(map),msg_err("invalid character in map ", argv[1]),1);
	if(ft_check_map_dir(map->tab_fd, map))
		return (destroy_mlx(map),msg_err("erreur parse direction ou erreur chemin texture  ", argv[1]),1);//changer msg erreur
	if(ft_check_argcolor(map->tab_fd, map))
		return (destroy_mlx(map),msg_err("erreur parse color  ", argv[1]),1);//changer msg erreur	
	if(parse_map(map))
			return(destroy_mlx(map),msg_err("error parse carte ",argv[1]));
	if(ft_check_symbol(map))
			return(destroy_mlx(map),msg_err("error symbol carte ",argv[1]));
	if(ft_check_carte_line_empty(map))
			return(destroy_mlx(map),msg_err("map ligne dans carte ",argv[1]));
	if(check_player(map))
			return(destroy_mlx(map),msg_err("multiple player ou pas de player  ou non close",argv[1]));
	return(0);	
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
	game->texture[1].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->south, &game->texture[1].width, &game->texture[1].height);
	game->texture[2].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->west, &game->texture[2].width, &game->texture[2].height);
	game->texture[3].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->east, &game->texture[3].width, &game->texture[3].height);
	ft_textures_addr(game);
}

void	assign_direction(t_data *game)
{
	if (game->direction.N == 1)
		game->ray.dir.x = -1;
	if (game->direction.S == 1)
		game->ray.dir.x = 1;
	if (game->direction.E == 1)
		game->ray.dir.y = 1;
	if (game->direction.W == 1)
		game->ray.dir.y = -1;
	if (game->direction.N == 1)
		game->ray.plane.y = 0.66;
	if (game->direction.S == 1)
		game->ray.plane.y = -0.66;
	if (game->direction.E == 1)
		game->ray.plane.x = 0.66;
	if (game->direction.W == 1)
		game->ray.plane.x = -0.66;
}


void	ft_init(t_data *data)
{
	data->mlx.forward = 0;
	data->mlx.back = 0;
	data->mlx.left = 0;
	data->mlx.right = 0;
	data->mlx.rotate_right = 0;
	data->mlx.rotate_left = 0;
	data->ray.pos.x = (double)data->pos_x + 0.5;
	data->ray.pos.y = (double)data->pos_y + 0.5;
	data->ray.dir.x = 0;
	data->ray.dir.y = 0;
	data->ray.plane.x = 0;
	data->ray.plane.y = 0;
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


int main(int argc,char **argv)
{
	t_data data;
	
	setup_game(&data);
	//int i=0;
	if(argc==2)
	{
		if(!ft_check_cub(argv[1]))//verifier .cub
			return(msg_err("error extention .cub ",argv[1]));
		ft_parsing_fd(&data,argv);//parsing	
		if (ft_initialise_and_create_window(&data))
		{
			ft_mlx(&data);
		}
		destroy_mlx(&data);
    }
	return(0);
}
