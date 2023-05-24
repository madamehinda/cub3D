/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:53:42 by hferjani          #+#    #+#             */
/*   Updated: 2023/05/24 16:25:57 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "Libft/get_next_line.h"
# include "Libft/libft.h"
# include "Libft/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_pos
{
	double	x;
	double	y;
} t_pos;

typedef	struct s_player
{
	double	x;
	double	y;
	// int		map_x;
	// int		map_y;
	t_pos	dir;
	t_pos	plane;
} t_player;

typedef struct s_data
{
	char	**map;
	// int		height;
	// int		width;
	// int		len;
	// int		rectangle;
	// int		collectible;
	// int		col_counter;
	// int		exit;
	// int		player;
	void	*mlx_ptr;
	void	*mlx_win;
	//void	*img_wall;
	void	*ceiling;
	void    *floor;
	t_player	player;
}	t_data;


#endif