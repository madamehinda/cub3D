/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:54:57 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/23 19:51:56 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int     rgb_to_int(int r, int g, int b)
// {
//     return (r << 16 | g << 8 | b);
// }

// void    ft_color_sky_and_floor(t_data *data)
// {
//     int x;
//     int y;
//     int color_sky;
//     int color_floor;

//     x = 0;
//     y = 0;
//     color_sky = rgb_to_int(data->c_rgb[0], data->c_rgb[1], data->c_rgb[2]);
//     color_floor = rgb_to_int(data->f_rgb[0], data->f_rgb[1], data->f_rgb[2]);
//     // printf("color ceiling = %d\n", color_sky);
//     // printf("color floor = %d\n", color_floor);
//     data->width = DISPLAY_WIDTH;
//     data->height = DISPLAY_HEIGHT;
//     while (x < data->width)
//     {
//         while (y < data->height)
//         {
//             if (y < data->height / 2)
//                 img_pix_put_color(data, x, y, color_sky);
//             else
//                 img_pix_put_color(data, x, y, color_floor);
//             y++;
//         }
//         y = 0;
//         x++;
//     }
// }


// int    render_all(t_data *data)
// {
//     ft_color_sky_and_floor(data);
//     raycasting(data);
//     mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
//     // mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->minimap.img_ptr, 10, 10);
//     //mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
//     return (0);
// }