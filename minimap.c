/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:52:00 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/24 14:46:19 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    ft_setup(t_data *data)
// {
// 	double scaled_x;
// 	double scaled_y;
// 	double end_x;
// 	double end_y;
// 	int color;

// 	//ft_set_minimap(data);
// 	printf("player pos x setup= %f\n", data->player.position.x);
// 	printf("player pos y setup= %f\n", data->player.position.y);
// 	scaled_x = (data->player.position.x * MINIMAP_SCALE_FACTOR) * TILE_SIZE;
// 	scaled_y = (data->player.position.y * MINIMAP_SCALE_FACTOR) * TILE_SIZE;
//     //ft_set_minimap(data);
//     color = mlx_get_color_value(data->mlx_ptr, 0xFF0000);
// 	mlx_pixel_put(data->mlx_ptr, data->mlx_win,scaled_x+HALF_TILE,scaled_y+HALF_TILE, color);
// 	end_x = scaled_x+HALF_TILE + cos(data->player.rotation_angle) * 40;
// 	end_y = scaled_y+HALF_TILE + sin(data->player.rotation_angle) * 40;
// 	mlx_render_draw_line(data->mlx_ptr,data->mlx_win,scaled_x+HALF_TILE,scaled_y+HALF_TILE,end_x,end_y,color);
//}



// void mlx_render_draw_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2, int color)
// {
//     int dx = x2 - x1;
//     int dy = y2 - y1;
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

//     float xIncrement = (float)dx / steps;
//     float yIncrement = (float)dy / steps;

//     float x = (float)x1;
//     float y = (float)y1;

//     for (int i = 0; i <= steps; i++)
//     {
//         mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, color);
//         x += xIncrement;
//         y += yIncrement;
//     }
// }