/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:57:53 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 13:40:12 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Algo raycasting: généré représentation 3d. gere incrementation rayon emis 
// depuis la camera jusqu'à contact avec mur
void	ft_increment_ray(t_data *game)
{
	while (game->ray.hit == 0)
	{
		game->negatif = 0;
		if (game->ray.side_dist.x < game->ray.side_dist.y)
		{
			game->ray.side_dist.x += game->ray.delta_dist.x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist.y += game->ray.delta_dist.y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->ray.map_x < 0 || game->ray.map_y < 0)
		{
			game->negatif = 1;
			break ;
		}
		if (game->tab[game->ray.map_x][game->ray.map_y] == '1')
			game->ray.hit = 1;
	}
	ft_startend(game);
}

// Calcul pour dessin de colonne de mur apres que le rayon ait touche le mur
void	ft_startend(t_data *game)
{
	if (game->negatif == 1)
		return ;
	if (game->ray.side == 0)
		game->ray.perp_wall_dist = ((double)game->ray.map_x - game->ray.pos.x
				+ (1 - (double)game->ray.step_x) / 2) / game->ray.ray_dir.x;
	else
		game->ray.perp_wall_dist = ((double)game->ray.map_y - game->ray.pos.y
				+ (1 - (double)game->ray.step_y) / 2) / game->ray.ray_dir.y;
	game->ray.line_height = (int)(DISPLAY_HEIGHT / game->ray.perp_wall_dist);
	game->ray.draw_start = -game->ray.line_height / 2 + DISPLAY_HEIGHT / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + DISPLAY_HEIGHT / 2;
	if (game->ray.draw_end >= DISPLAY_HEIGHT || game->ray.draw_end < 0)
		game->ray.draw_end = DISPLAY_HEIGHT - 1;
}

static int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

// Dessin colonne de mur
int	display_column(t_data *game, int x)
{
	int	i;
	int	j;

	j = -1;
	if (game->negatif == 1)
		return (0);
	game->ceiling = rgb_to_int(game->c_rgb[0], game->c_rgb[1], game->c_rgb[2]);
	game->floor = rgb_to_int(game->f_rgb[0], game->f_rgb[1], game->f_rgb[2]);
	game->ray.draw_end = DISPLAY_HEIGHT - game->ray.draw_start;
	i = game->ray.draw_end;
	while (++j < game->ray.draw_start)
		game->mlx.addr[j * game->mlx.line_length / 4 + x] = game->ceiling;
	if (j <= game->ray.draw_end)
		display_texture(game, x, j);
	j = i;
	while (++j < DISPLAY_HEIGHT)
		game->mlx.addr[j * game->mlx.line_length / 4 + x] = game->floor;
	return (0);
}
