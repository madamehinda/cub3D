/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_cube3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:49:36 by hferjani          #+#    #+#             */
/*   Updated: 2023/06/02 20:49:37 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int msg_err(char *msg,char *argv)
{
	printf("ERROR\n");
	printf("%s",msg);
	if(argv)
		printf("%s",argv);
	printf("\n");
	exit(EXIT_FAILURE);
	return(1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
void	ft_free(char **str)
{
	int	i;

	i = 0;
	if(!str)
		return;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
int ft_check_char(char *str)
{
	int i= 0;
	while(str[i] && str[i] != '\n')
	{
		if (str[i] == ' ' )
			i++;
	}
	if(str[i]=='\n')
		return(0);
	else 
		return(1);
}