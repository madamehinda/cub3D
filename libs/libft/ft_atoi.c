/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:17:24 by imraoui           #+#    #+#             */
/*   Updated: 2023/05/25 18:23:30 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoii(const char *str)
{
	int			i;
 	int	nb;

	i = 0;
	nb = 0;
	if (!str[i])
		return (-1);
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if ((nb > 255) || (nb < 0) || !str[0])
		return (-1);
	if (str[i] == '\n')
	{
		if (str[i + 1] != '\0')
			return (-1);
	}
	return (nb);
}
/*
int main()
{
	// printf("%d\n",ft_atoi("++1234ab567"));
	printf("%d\n",atoi("\e475"));
	printf("%d\n",ft_atoi("\e475"));
	return (0);
}
*/
