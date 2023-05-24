/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:47:08 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/20 14:54:48 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	longueur_nbr(long nbr)
{
	long	len;

	len = 0;
	if (nbr == 0)
		len++;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	new_n;
	long	len;

	new_n = n;
	len = longueur_nbr(new_n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (new_n == 0)
		str[0] = '0';
	if (new_n < 0)
	{
		str[0] = '-';
		new_n *= -1;
	}
	while (new_n > 0)
	{
		str[--len] = new_n % 10 + '0';
		new_n = new_n / 10;
	}
	return (str);
}
/*Alloue (avec malloc(3)) et retourne une chaîne
de caractères représentant l’entier ’n’ reçu en
argument. Les nombres négatifs doivent être gérés.*/