/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 01:09:27 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 13:47:08 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_north(t_data *data)
{
	data->wall_north.img = NULL;
	data->wall_north.img = mlx_xpm_file_to_image(data->mlx.mlx_ptr, data->north,
			&data->wall_north.width, &data->wall_north.height);
	if (!data->wall_north.img)
	{
		msg_err("mlx_xpm_file_to_image() failed", NULL);
		exit_game(data);
	}
	data->wall_north.addr = (int *)mlx_get_data_addr(data->wall_north.img,
			&data->wall_north.bits_per_pixel,
			&data->wall_north.line_length,
			&data->wall_north.endian);
	if (!data->wall_north.addr)
	{
		msg_err("mlx_get_data_addr() failed", NULL);
		exit_game(data);
	}
}

void	init_south(t_data *data)
{
	data->wall_south.img = NULL;
	data->wall_south.img = mlx_xpm_file_to_image(data->mlx.mlx_ptr, data->south,
			&data->wall_south.width, &data->wall_south.height);
	if (!data->wall_south.img)
	{
		msg_err("mlx_xpm_file_to_image() failed", NULL);
		exit_game(data);
	}
	data->wall_south.addr = (int *)mlx_get_data_addr(data->wall_south.img,
			&data->wall_south.bits_per_pixel,
			&data->wall_south.line_length,
			&data->wall_south.endian);
	if (!data->wall_south.addr)
	{
		msg_err("mlx_get_data_addr() failed", NULL);
		exit_game(data);
	}
}

void	init_west(t_data *data)
{
	data->wall_west.img = NULL;
	data->wall_west.img = mlx_xpm_file_to_image(data->mlx.mlx_ptr, data->west,
			&data->wall_west.width, &data->wall_west.height);
	if (!data->wall_west.img)
	{
		msg_err("mlx_xpm_file_to_image() failed", NULL);
		exit_game(data);
	}
	data->wall_west.addr = (int *)mlx_get_data_addr(data->wall_west.img,
			&data->wall_west.bits_per_pixel,
			&data->wall_west.line_length,
			&data->wall_west.endian);
	if (!data->wall_west.addr)
	{
		msg_err("mlx_get_data_addr() failed", NULL);
		exit_game(data);
	}
}

void	init_east(t_data *data)
{
	data->wall_east.img = NULL;
	data->wall_east.img = mlx_xpm_file_to_image(data->mlx.mlx_ptr, data->east,
			&data->wall_east.width, &data->wall_east.height);
	if (!data->wall_east.img)
	{
		msg_err("mlx_xpm_file_to_image() failed", NULL);
		exit_game(data);
	}
	data->wall_east.addr = (int *)mlx_get_data_addr(data->wall_east.img,
			&data->wall_east.bits_per_pixel,
			&data->wall_east.line_length,
			&data->wall_east.endian);
	if (!data->wall_east.addr)
	{
		msg_err("mlx_get_data_addr() failed", NULL);
		exit_game(data);
	}
}
