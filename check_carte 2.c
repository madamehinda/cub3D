
#include "cub3d.h"

void	ft_backtacking(t_data *map,int i,int j)
{
	int flag=0;
	int start_i=i;
	int start_j=j;
	while(flag<4)
	{
		if(flag==0)
		{
			while (map->dup[i][j] && (map -> dup[i][j] == '0' || map->dup[i][j]=='P') && map -> dup[i][j] != '1')
			{
				map->dup[i][j]='P';
				j++;
			}
			flag++;
			j=start_j;
		}
		if(flag==1)
		{
			while (map->dup[i][j] && (map -> dup[i][j] == '0' || map->dup[i][j]=='P') && map -> dup[i][j] != '1' )
			{
				map->dup[i][j]='P';
				j--;
			}
			flag++;
			j=start_j;
		}
		if(flag==2)
		{
			while (map->dup[i][j] && (map -> dup[i][j] == '0' || map->dup[i][j]=='P') && map -> dup[i][j] != '1' )
			{
				map->dup[i][j]='P';
				i++;
			}
			flag++;
			i=start_i;
		}
		if(flag==3)
		{
			while (map->dup[i][j] && (map -> dup[i][j] == '0' || map->dup[i][j]=='P') && map -> dup[i][j] != '1' )
			{
				map->dup[i][j]='P';
				i--;
			}
			flag++;
			i=start_i;
		}
}
}
int	ft_backtacking_close(t_data *map,int i,int j)
{
	int start_i;
	int start_j;
	int flag=0;
	start_i=i;
	start_j=j;
	while(flag<4)
	{
	if(flag==0)
	{
	while (map->dup[i][j] && map -> dup[i][j] == 'P' )
		j++;
	if(map->dup[i][j]!='1')
		return(1);
	flag++;
	j=start_j;
	}
	if(flag==1)
	{
	while (map->dup[i][j] && map -> dup[i][j] == 'P' )
		j--;
	if(map->dup[i][j]!='1')
		return(2);
	j=start_j;
	flag++;
	}
	if(flag==2)
	{
	while (map->dup[i][j] && map -> dup[i][j] == 'P' )
		i++;
	if(map->dup[i][j]!='1')
		return(3);
	i=start_i;
	flag++;
	}
	if(flag==3)
	{
	while (map->dup[i][j] && map -> dup[i][j] == 'P' )
		i--;
	if(map->dup[i][j]!='1')
		return(4);
	i=start_i;
	flag++;
	}
	}
	return(0);
}


int	ft_dup(t_data *map)
{
	int	i;
	int j;
	i = 0;
	map->dup = (char **) malloc(sizeof(char *) * (map -> height + 1));
	if(!map->dup)
		return(1);
	map->dup[map -> height] = NULL;
	while(map->tab[i])
	{
			map->dup[i] = ft_strdup(map->tab[i]);
			i++;
	}
	map->dup[i]= '\0';
	i=0;
	while(map->dup[i])
	{
		j=0;
		while(map->dup[i][j])
		{
			if(map->dup[i][j]=='0' || map->dup[i][j]==' ' || map->dup[i][j]=='N' || map->dup[i][j]=='E' || map->dup[i][j]=='S' || map->dup[i][j]=='W')
				map->dup[i][j]='0';
			j++;
		}
		i++;
	}
	ft_backtacking(map,map->pos_x,map->pos_y);
	if(ft_backtacking_close(map,map->pos_x,map->pos_y))
		return(1);
	return(0);
}


