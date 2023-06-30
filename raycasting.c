/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:54:25 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 13:41:30 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Loop principale (rendu, maj affichage, maj mouvements)
int	ft_raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < DISPLAY_WIDTH)
	{
		init_again(data, x);
		ft_sidedist(data);
		ft_sidedist2(data);
		ft_increment_ray(data);
		display_column(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr,
		data->mlx.mlx_win, data->mlx.img, 0, 0);
	ft_forward_back(data);
	ft_left_right(data);
	ft_rotate_right(data);
	ft_swap(data);
	return (0);
}

// Calcul distance départ du rayon et premier contact mur, sur axes x et Y
void	ft_sidedist(t_data *game)
{
	if (game->negatif == 1)
		return ;
	if (game->ray.ray_dir.x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist.x = (game->ray.pos.x - game->ray.map_x)
			* game->ray.delta_dist.x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist.x = (game->ray.map_x + 1.0 - game->ray.pos.x)
			* game->ray.delta_dist.x;
	}
}

void	ft_sidedist2(t_data *game)
{
	if (game->negatif == 1)
		return ;
	if (game->ray.ray_dir.y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist.y = (game->ray.pos.y - game->ray.map_y)
			* game->ray.delta_dist.y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist.y = (game->ray.map_y + 1.0 - game->ray.pos.y)
			* game->ray.delta_dist.y;
	}
}
