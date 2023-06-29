/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:16:57 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/29 12:35:15 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Init direction texture/direction position
void	ft_init_textures(t_data *game)
{
	if (game->ray.side == 0 && game->ray.ray_dir.x < 0)
		game->t.texdir = 0;
	if (game->ray.side == 0 && game->ray.ray_dir.x >= 0)
		game->t.texdir = 1;
	if (game->ray.side == 1 && game->ray.ray_dir.y < 0)
		game->t.texdir = 2;
	if (game->ray.side == 1 && game->ray.ray_dir.y >= 0)
		game->t.texdir = 3;
	if (game->ray.side == 0)
		game->t.wall_x = game->ray.pos.y + game->ray.perp_wall_dist
			* game->ray.ray_dir.y;
	else
		game->t.wall_x = game->ray.pos.x + game->ray.perp_wall_dist
			* game->ray.ray_dir.x;
	game->t.wall_x -= floor(game->t.wall_x);
}

void	display_texture(t_data *game, int x, int y)
{
	y = game->ray.draw_start - 1;
	ft_init_textures(game);
	game->t.step = 1.0 * game->texture[0].height / game->ray.line_height;
	game->t.tex_x = (int)(game->t.wall_x
			* (double)game->texture[game->t.texdir].width);
	if (game->ray.side == 0 && game->ray.ray_dir.x > 0)
		game->t.tex_x = game->texture[game->t.texdir].width - game->t.tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir.x < 0)
		game->t.tex_x = game->texture[game->t.texdir].width - game->t.tex_x - 1;
	game->t.tex_pos = (game->ray.draw_start - DISPLAY_HEIGHT / 2
			+ game->ray.line_height / 2) * game->t.step;
	while (++y <= game->ray.draw_end)
	{
		game->t.tex_y = (int)game->t.tex_pos
			& (game->texture[game->t.texdir].height - 1);
		game->t.tex_pos += game->t.step;
		if (y < DISPLAY_HEIGHT && x < DISPLAY_WIDTH)
			game->mlx.addr[y * game->mlx.line_length / 4 + x]
				= game->texture[game->t.texdir].addr[game->t.tex_y
				* game->texture[game->t.texdir].line_length / 4
				+ game->t.tex_x];
	}
}
