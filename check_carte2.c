/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_carte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:57:06 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/25 14:16:31 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_j_inc(t_data *map, int *flag)
{
	int i;
	int j;
	int start_j;

	i = map->pos_x;
	j = map->pos_y;
	start_j = j;
	while (map->dup[i][j] && (map->dup[i][j] == '0' || map->dup[i][j] == 'P') && map->dup[i][j] != '1')
	{
		map->dup[i][j] = 'P';
		j++;
	}
	(*flag)++;
	j = start_j;
}

void move_j_dec(t_data *map, int *flag)
{
	int i;
	int j;
	int start_j;

	i = map->pos_x;
	j = map->pos_y;
	start_j = j;
	while (map->dup[i][j] && (map->dup[i][j] == '0' || map->dup[i][j] == 'P') && map->dup[i][j] != '1')
	{
		map->dup[i][j] = 'P';
		j--;
	}
	(*flag)++;
	j = start_j;
}

void move_i_inc(t_data *map, int *flag)
{
	int i;
	int j;
	int start_i;

	i = map->pos_x;
	j = map->pos_y;
	start_i = i;
	while (i<map->height && (map->dup[i][j] == '0' || map->dup[i][j] == 'P') && map->dup[i][j] != '1')
	{
		map->dup[i][j] = 'P';
		i++;
	}
	(*flag)++;
	i = start_i;
}

void move_i_dec(t_data *map, int *flag)
{
	int i;
	int j;
	int start_i;

	i = map->pos_x;
	j = map->pos_y;
	start_i = i;
	while (i != 1 && (map->dup[i][j] == '0' || map->dup[i][j] == 'P') && map->dup[i][j] != '1')
	{
		map->dup[i][j] = 'P';
		i--;
	}
	(*flag)++;
	i = start_i;
}
void ft_backtacking(t_data *map)
{
	int flag;

	flag = 0;
	while (flag < 4)
	{
		if (flag == 0)
			move_j_inc(map, &flag);
		if (flag == 1)
			move_j_dec(map, &flag);
		if (flag == 2)
			move_i_inc(map, &flag);
		if (flag == 3)
			move_i_dec(map, &flag);
	}
}

int verif_j_inc(t_data *map, int *flag)
{
	int i;
	int j;
	int start_j;
	int k = 0;
	i = map->pos_x;
	j = map->pos_y;
	start_j = j;
	while (map->dup[i][j]!='0' && map->dup[i][j] == 'P')
		j++;
	printf("j====%d",j);
	while (k < map->height -1 && map->dup[k][j] == '1')
		k++;
	printf("k====%d",k);
	printf("caracter====%c\n",map->dup[k][j]);
	if (k != map->height)
		return (1);
	(*flag)++;
	j = start_j;
	return (0);
}
int verif_j_dec(t_data *map, int *flag)
{
	int i;
	int j;
	int start_j;
	int k = 0;
	i = map->pos_x;
	j = map->pos_y;
	start_j = j;
	while (j != 1 && map->dup[i][j] == 'P')
		j--;
	printf("%d",j);
	while (map->dup[k][j] == '1')
		k++;
	if (k != map->height)
		return (1);
	j = start_j;
	(*flag)++;
	return (0);
}
int verif_i_inc(t_data *map, int *flag)
{
	int i;
	int j;
	int start_i;
	int k = 0;
	i = map->pos_x;
	j = map->pos_y;
	start_i = i;
	while (i<map->height -1 && map->dup[i][j] == 'P')
		i++;
	while (map->dup[i][k]!='0' && map->dup[i][k] == '1')
		k++;
	if (!map->dup[i][k])
		return (1);
	i = start_i;
	(*flag)++;
	return (0);
}
int verif_i_dec(t_data *map, int *flag)
{
	int i;
	int j;
	int start_i;

	i = map->pos_x;
	j = map->pos_y;
	int k = 0;
	start_i = i;
	while (i != 1 && map->dup[i][j] == 'P')
		i--;
	while (map->dup[i][k] && map->dup[i][k] == '1')
		k++;
	printf("%c",map->dup[i][k]);
	if (!map->dup[i][k])
		return (1);
	i = start_i;
	(*flag)++;
	return (0);
}
int ft_backtacking_close(t_data *map)
{
	int flag;

	flag = 0;
	while (flag < 4)
	{
		if (flag == 0)
			if (verif_j_inc(map, &flag))
				return(1);
		if (flag == 1)
		{
			if (verif_j_dec(map, &flag))
			{
				printf("%d", verif_j_dec(map, &flag));
				return (2);
			}
		}
		if (flag == 2)
		{
			if (verif_i_inc(map, &flag))
			{
				printf("%d", verif_i_inc(map, &flag));
				return (3);
			}
		}
		if (flag == 3)
		{
			if (verif_i_dec(map, &flag))
			{
				printf("%d", verif_i_dec(map, &flag));
				return (4);
			}
		}
	}
	return (0);
}
int	malloc_dup(t_data *map)
{
	int	i;

	i = 0;
	map->dup = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->dup)
		return (1);
	map->dup[map->height] = NULL;
	while (map->tab[i])
	{
		map->dup[i] = ft_strdup(map->tab[i]);
		i++;
	}
	map->dup[i] = '\0';
	return (0);
}
int	ft_dup(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	if (malloc_dup(map))
		return (1);
	while (map->dup[i])
	{
		j = 0;
		while (map->dup[i][j])
		{
			if (map->dup[i][j] == '0' || map->dup[i][j] == ' '
				|| map->dup[i][j] == 'N' || map->dup[i][j] == 'E'
				|| map->dup[i][j] == 'S' || map->dup[i][j] == 'W')
				map->dup[i][j] = '0';
			j++;
		}
		i++;
	}
	ft_backtacking(map);
	if (ft_backtacking_close(map))
		return (1);
	return (0);
}
