/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:39:43 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 12:58:58 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_swap(t_data *game)
{
	void	*tmp;

	tmp = game->mlx.img;
	game->mlx.img = game->mlx.img_swap;
	game->mlx.img_swap = tmp;
	tmp = game->mlx.addr;
	game->mlx.addr = game->mlx.addr_swap;
	game->mlx.addr_swap = tmp;
}

int	ft_press(int keycode, t_data *game)
{
	if (keycode == XK_Escape)
		exit_game(game);
	else if (keycode == FORWARD_W)
		game->mlx.forward = 1;
	else if (keycode == BACK_S)
		game->mlx.back = 1;
	else if (keycode == LEFT_A)
		game->mlx.left = 1;
	else if (keycode == RIGHT_D)
		game->mlx.right = 1;
	else if (keycode == ROTATE_LEFT)
		game->mlx.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		game->mlx.rotate_right = 1;
	return (1);
}

int	ft_release(int keycode, t_data *game)
{
	if (keycode == FORWARD_W)
		game->mlx.forward = 0;
	else if (keycode == BACK_S)
		game->mlx.back = 0;
	else if (keycode == LEFT_A)
		game->mlx.left = 0;
	else if (keycode == RIGHT_D)
		game->mlx.right = 0;
	else if (keycode == ROTATE_LEFT)
		game->mlx.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		game->mlx.rotate_right = 0;
	return (1);
}
