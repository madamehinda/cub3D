/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:57:11 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/24 16:55:08 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*free and exits the game*/
int	exit_game(t_data *map)
{
	int	i;

	printf("Bye Bitch!\n");
	i = 0;
	destroy_mlx(map);
	while (i < 4)
	{
		if (map->texture[i].img)
			mlx_destroy_image(map->mlx.mlx_ptr, map->texture[i].img);
		i++;
	}
	if (map->mlx.img)
		mlx_destroy_image(map->mlx.mlx_ptr, map->mlx.img);
	if (map->mlx.img_swap)
		mlx_destroy_image(map->mlx.mlx_ptr, map->mlx.img_swap);
	if (map->mlx.mlx_win)
		mlx_destroy_window(map->mlx.mlx_ptr, map->mlx.mlx_win);
	if (map->mlx.mlx_ptr)
		mlx_destroy_display(map->mlx.mlx_ptr);
	free(map->mlx.mlx_ptr);
	exit(0);
}
