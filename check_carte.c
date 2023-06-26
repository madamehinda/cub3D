/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_carte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:57:06 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/26 14:13:48 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_backtacking(t_data *data, int i, int j)
{
    if (i >= 0 && i < data->height && j >= 0  && data->dup[i][j])
    {
        printf("%s\n", data->dup[i]);

        if (data->dup[i][j] == '0' || data->dup[i][j] == 'N' || data->dup[i][j] == 'E' || data->dup[i][j] == 'S' || data->dup[i][j] == 'W')
            data->dup[i][j] = 'P';
        else
            return 0; // Condition de sortie lorsque le caractère n'est pas souhaité

        ft_backtacking(data, i, j + 1);
        ft_backtacking(data, i, j - 1);
        ft_backtacking(data, i + 1, j);
        ft_backtacking(data, i - 1, j);
    }

    return 0;
}

int	ft_dup(t_data *map)
{
	int	i;
	int j;
	i = 0;
	map->dup = (char **) malloc(sizeof(char *) * (map -> height + 1));
	if(!map->dup)
		return(1);
	map->dup[map->height] = NULL;
	while(map->tab[i])
	{
			map->dup[i] = ft_strdup(map->tab[i]);
			i++;
	}
	map->dup[i]= '\0';
	// i=0;
	// while(map->dup[i])
	// {
	// 	j=0;
	// 	while(map->dup[i][j])
	// 	{
	// 		if(map->dup[i][j]=='0' || map->dup[i][j]==' ' || map->dup[i][j]=='N' || map->dup[i][j]=='E' || map->dup[i][j]=='S' || map->dup[i][j]=='W')
	// 			map->dup[i][j]='0';
	// 		j++;
	// 	}
	// 	i++;
	// }
	i = 0;
	ft_backtacking(map,map->pos_x,map->pos_y);
	printf("resulat\n");
	while (map->dup[i])
	{
		j = 0;
		while(map->dup[i][j])
		{
			printf("%c",map->dup[i][j]);
			j++;
		}
		i++;
	}
	
	// if(ft_backtacking_close(map,map->pos_x,map->pos_y))
	// 	return(1);
	return(0);
}

