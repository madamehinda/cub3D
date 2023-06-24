/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:48:40 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/24 00:29:40 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Init vue, vitesse déplacement et rotation
void	init_again(t_data *game, int x)
{
	game->ray.hit = 0;
	game->ray.perp_wall_dist = 0;
	game->ray.camera_x = 2 * x / (double)DISPLAY_WIDTH - 1;
	game->ray.ray_dir.x = game->ray.dir.x + game->ray.plane.x * game->ray.camera_x;
	game->ray.ray_dir.y = game->ray.dir.y + game->ray.plane.y * game->ray.camera_x;
	game->ray.map_x = (int)game->ray.pos.x;
	game->ray.map_y = (int)game->ray.pos.y;
	game->ray.move_speed = 0.1;
	game->ray.rot_speed = 0.033 * 1.8;
	init_again2(game);
}

// Init/Calcul valeur raycasting (distance rayon/grille X et Y)
void	init_again2(t_data *game)
{
	if (game->ray.ray_dir.y == 0)
		game->ray.delta_dist.x = 0;
	else if (game->ray.ray_dir.x == 0)
		game->ray.delta_dist.x = 1;
	else
		game->ray.delta_dist.x = sqrt(1 + (game->ray.ray_dir.y * \
		game->ray.ray_dir.y) / (game->ray.ray_dir.x * game->ray.ray_dir.x));
	if (game->ray.ray_dir.x == 0)
		game->ray.delta_dist.y = 0;
	else if (game->ray.ray_dir.y == 0)
		game->ray.delta_dist.y = 1;
	else
		game->ray.delta_dist.y = sqrt(1 + (game->ray.ray_dir.x * \
		game->ray.ray_dir.x) / (game->ray.ray_dir.y * game->ray.ray_dir.y));
}

void	initialise_window(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
	{
		msg_err("mlx_init() failed", NULL);
		exit_game(data);
	}
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx_ptr, DISPLAY_WIDTH, \
		DISPLAY_HEIGHT, "Cub3D");
	if (!data->mlx.mlx_win)
	{
		msg_err("mlx_new_window() failed", NULL);
		exit_game(data);
	}
}


// void    initialise_minimap(t_data *data)
// {
//     data->minimap.img_ptr = mlx_new_image(data->mlx_ptr, MINIMAP_SCALE_FACTOR * data->width, MINIMAP_SCALE_FACTOR * data->height);
// 	if (!data->minimap.img_ptr)
// 	{
// 		msg_err("minimap = mlx_new_image() failed", NULL);
// 		exit_game(data);
// 	}
// 	data->minimap.addr = mlx_get_data_addr(data->minimap.img_ptr, &data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
// 	if (!data->minimap.addr)
// 	{
// 		msg_err("minimap = mlx_get_data_addr() failed", NULL);
// 		exit_game(data);
// 	}
	//render_minimap(data);
//}

