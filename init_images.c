/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:58:54 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/30 12:56:39 by hferjani         ###   ########.fr       */
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

// Obtenir addr textures
void	ft_textures_addr(t_data *game)
{
	game->texture[0].addr = (int *)mlx_get_data_addr(game->texture[0].img,
			&game->texture[0].bits_per_pixel, &game->texture[0].line_length,
			&game->texture[0].endian);
	game->texture[1].addr = (int *)mlx_get_data_addr(game->texture[1].img,
			&game->texture[1].bits_per_pixel, &game->texture[1].line_length,
			&game->texture[1].endian);
	game->texture[2].addr = (int *)mlx_get_data_addr(game->texture[2].img,
			&game->texture[2].bits_per_pixel, &game->texture[2].line_length,
			&game->texture[2].endian);
	game->texture[3].addr = (int *)mlx_get_data_addr(game->texture[3].img,
			&game->texture[3].bits_per_pixel, &game->texture[3].line_length,
			&game->texture[3].endian);
}

void	texture_not_found(t_data *game)
{
	printf("Error\nTexture not found");
	exit_game(game);
}

// Chargement des textures
void	ft_textures(t_data *game)
{
	game->texture[0].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->north, &game->texture[0].width, &game->texture[0].height);
	if (!game->texture[0].img)
		texture_not_found(game);
	game->texture[1].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->south, &game->texture[1].width, &game->texture[1].height);
	if (!game->texture[1].img)
		texture_not_found(game);
	game->texture[2].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->west, &game->texture[2].width, &game->texture[2].height);
	if (!game->texture[2].img)
		texture_not_found(game);
	game->texture[3].img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->east, &game->texture[3].width, &game->texture[3].height);
	if (!game->texture[3].img)
		texture_not_found(game);
	ft_textures_addr(game);
}
