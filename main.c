/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:14:32 by hferjani          #+#    #+#             */
/*   Updated: 2023/05/24 16:30:27 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data  *init_all(t_data *data)
{
    data = malloc(sizeof(t_data));
    if (!data)
        return(NULL);
    return(data);
}
void    set_player_pos(t_data *data, char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S'|| map[i][j] == 'N')
            {
                data->player.y = i;
                data->player.x = j;
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    t_data *data;

    data = NULL;
    if(argc != 2)
        return(1);
    data = init_all(data);
    
}