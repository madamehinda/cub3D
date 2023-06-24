/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:54:25 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/24 01:51:50 by hferjani         ###   ########.fr       */
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

// void    draw_each_column(t_data *data, int x)
// {
//     while (data->ray.draw_start < data->ray.draw_end)
//     {
//         data->ray.tex_y = (int)data->ray.tex_pos & (TEX_HEIGHT - 1);
//         data->ray.tex_pos += data->ray.step;
//         if(data->ray.side == 1 && data->ray.direction.y < 0)
//         draw(data, x, SOUTH);
//         if(data->ray.side == 1 && data->ray.direction.y > 0)
//         draw(data, x, NORTH);
//         if(data->ray.side == 0 && data->ray.direction.x < 0)
//         draw(data, x, EAST);
//         if(data->ray.side == 0 && data->ray.direction.x > 0)
//         draw(data, x, WEST);
//         data->ray.draw_start++;
//     }
// }

