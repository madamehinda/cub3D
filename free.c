/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:57:11 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/23 19:48:41 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*free and exits the game*/
int	exit_game(t_data *map)
{
	printf("Bye Bitch!\n");
	// mlx_destroy_image(map->mlx, map->img_player);
	// mlx_destroy_image(map->mlx, map->img_collectible);
	// mlx_destroy_image(map->mlx, map->img_exit);
	// mlx_destroy_image(map->mlx, map->img_wall);
	// mlx_destroy_image(map->mlx, map->img_background);
	if(map->tab)
		ft_strlen_mat(map->tab);
	if(map->mlx.mlx_win)
		mlx_destroy_window(map->mlx.mlx_ptr, map->mlx.mlx_win);
	if(map->mlx.mlx_ptr)
		mlx_destroy_display(map->mlx.mlx_ptr);
	free(map->mlx.mlx_ptr);
	//free(map);
	exit (0);
}
