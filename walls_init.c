/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 01:09:27 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/24 00:03:37 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_img(t_data *data)
{
    data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	data->mlx.addr = (int *)mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel, \
			&data->mlx.line_length, &data->mlx.endian);
	data->mlx.img_swap = mlx_new_image(data->mlx.mlx_ptr, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	data->mlx.addr_swap = (int *)mlx_get_data_addr(data->mlx.img_swap,
			&data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
}
