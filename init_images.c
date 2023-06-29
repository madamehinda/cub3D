/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:58:54 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/29 12:53:22 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_data *data)
{
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, DISPLAY_WIDTH, \
		DISPLAY_HEIGHT);
	data->mlx.addr = (int *)mlx_get_data_addr(data->mlx.img, \
		&data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	data->mlx.img_swap = mlx_new_image(data->mlx.mlx_ptr, \
		DISPLAY_WIDTH, DISPLAY_HEIGHT);
	data->mlx.addr_swap = (int *)mlx_get_data_addr(data->mlx.img_swap,
			&data->mlx.bits_per_pixel, &data->mlx.line_length, \
			&data->mlx.endian);
}

int	ft_initialise_and_create_window(t_data *data)
{
	ft_init(data);
	assign_direction(data);
	initialise_window(data);
	ft_textures(data);
	init_img(data);
	return (1);
}
