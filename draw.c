/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:25:28 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/24 01:50:09 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// int	get_color_texture(t_data *data, int x, int y, int texture)
// {
//     if(texture == 0)
//         return (*(int *)(data->wall_north.addr + (y * data->wall_north.line_len + x * (data->wall_north.bpp / 8))));
//     else if(texture == 1)
//         return (*(int *)(data->wall_south.addr + (y * data->wall_south.line_len + x * (data->wall_south.bpp / 8))));
//     else if(texture == 2)
//         return (*(int *)(data->wall_west.addr + (y * data->wall_west.line_len + x * (data->wall_west.bpp / 8))));
//     else if(texture == 3)
//         return (*(int *)(data->wall_east.addr + (y * data->wall_east.line_len + x * (data->wall_east.bpp / 8))));
//     // else if(texture == 4)
//     //     return (*(int *)(data->sprite.addr + (y * data->sprite.line_len + x * (data->sprite.bpp / 8))));
//     return (0);
// }
void	img_pix_put_color(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > DISPLAY_HEIGHT - 1 || x < 0
		|| x > DISPLAY_WIDTH - 1)
		return ;
	pixel = data->mlx.addr[y * data->mlx.line_length / 4 + x];
	*(int *)pixel = color;

    
}


/*Elle récupère la couleur du pixel à partir de la texture correspondante
 en appelant get_color, puis utilise img_pix_put pour dessiner le pixel 
 à la position (x, draw_start) dans l'image data->img.*/
 
// void	draw(t_data *data, int x, int texture)
// {
// 	int	color;

// 	color = get_color_texture(data, data->ray.tex_x, data->ray.tex_y, texture);
// 	img_pix_put_color(data, x, data->ray.draw_start, color);
// }

