/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:30:39 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 13:00:00 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Déplacement du joueur (avant et arrière)
void	ft_forward_back(t_data *d)
{
	if (d->negatif == 1)
		return ;
	if (d->mlx.forward == 1)
	{
		if (d->tab[(int)(d->ray.pos.x + (d->ray.dir.x * d->ray.move_speed
					* 10))][(int)d->ray.pos.y] != '1')
			d->ray.pos.x += d->ray.dir.x * d->ray.move_speed;
		if (d->tab[(int)d->ray.pos.x][(int)(d->ray.pos.y + (d->ray.dir.y
				* d->ray.move_speed * 10))] != '1')
			d->ray.pos.y += d->ray.dir.y * d->ray.move_speed;
	}
	else if (d->mlx.back == 1)
	{
		if (d->tab[(int)(d->ray.pos.x - (d->ray.dir.x * d->ray.move_speed
					* 10))][(int)d->ray.pos.y] != '1')
			d->ray.pos.x -= d->ray.dir.x * d->ray.move_speed;
		if (d->tab[(int)d->ray.pos.x][(int)(d->ray.pos.y - (d->ray.dir.y
				* d->ray.move_speed * 10))] != '1')
			d->ray.pos.y -= d->ray.dir.y * d->ray.move_speed;
	}
}

// Déplacement du joueur (droite et gauche)
void	ft_left_right(t_data *data)
{
	if (data->negatif == 1)
		return ;
	if (data->mlx.right == 1)
	{
		if (data->tab[(int)(data->ray.pos.x + (data->ray.dir.y
					* data->ray.move_speed * 10))][(int)data->ray.pos.y] != '1')
			data->ray.pos.x += data->ray.dir.y * data->ray.move_speed;
		if (data->tab[(int)data->ray.pos.x][(int)(data->ray.pos.y
			- (data->ray.dir.x * data->ray.move_speed * 10))] != '1')
			data->ray.pos.y -= data->ray.dir.x * data->ray.move_speed;
	}
	else if (data->mlx.left == 1)
	{
		if (data->tab[(int)(data->ray.pos.x - (data->ray.dir.y
					* data->ray.move_speed * 10))][(int)data->ray.pos.y] != '1')
			data->ray.pos.x -= data->ray.dir.y * data->ray.move_speed;
		if (data->tab[(int)data->ray.pos.x][(int)(data->ray.pos.y
			- (data->ray.dir.x * data->ray.move_speed * 10))] != '1')
			data->ray.pos.y += data->ray.dir.x * data->ray.move_speed;
	}
}

// Déplacer camera vers la gauche, rotation vectorielle
void	ft_rotate_left(t_data *game)
{
	double	oldplanex;
	double	olddirx;

	if (game->negatif == 1)
		return ;
	oldplanex = game->ray.plane.x;
	olddirx = game->ray.dir.x;
	if (game->mlx.rotate_left == 1)
	{
		game->ray.dir.x = game->ray.dir.x * cos(game->ray.rot_speed / 2)
			- game->ray.dir.y * sin(game->ray.rot_speed / 2);
		game->ray.dir.y = olddirx * sin(game->ray.rot_speed / 2)
			+ game->ray.dir.y * cos(game->ray.rot_speed / 2);
		game->ray.plane.x = game->ray.plane.x * cos(game->ray.rot_speed / 2)
			- game->ray.plane.y * sin(game->ray.rot_speed / 2);
		game->ray.plane.y = oldplanex * sin(game->ray.rot_speed / 2)
			+ game->ray.plane.y * cos(game->ray.rot_speed / 2);
	}
}

// Déplacer camera vers la droite, rotation vectorielle
void	ft_rotate_right(t_data *game)
{
	double	oldplanex;
	double	olddirx;

	if (game->negatif == 1)
		return ;
	oldplanex = game->ray.plane.x;
	olddirx = game->ray.dir.x;
	if (game->mlx.rotate_right == 1)
	{
		game->ray.dir.x = game->ray.dir.x * cos(-game->ray.rot_speed / 2)
			- game->ray.dir.y * sin(-game->ray.rot_speed / 2);
		game->ray.dir.y = olddirx * sin(-game->ray.rot_speed / 2)
			+ game->ray.dir.y * cos(-game->ray.rot_speed / 2);
		game->ray.plane.x = game->ray.plane.x * cos(-game->ray.rot_speed / 2)
			- game->ray.plane.y * sin(-game->ray.rot_speed / 2);
		game->ray.plane.y = oldplanex * sin(-game->ray.rot_speed / 2)
			+ game->ray.plane.y * cos(-game->ray.rot_speed / 2);
	}
	ft_rotate_left(game);
}
