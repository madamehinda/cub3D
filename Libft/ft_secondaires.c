/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secondaires.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:07:41 by hferjani          #+#    #+#             */
/*   Updated: 2022/06/07 15:21:34 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	longueur_nbr(long nbr)
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

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar(nbr + '0');
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr %= 10;
		ft_putchar(nbr + '0');
	}
}

/*int	ft_itoa(unsigned int num)
{
	char	*str;
	int		i;

	if (num > 10)
		i = ft_itoa((num / 10));
	str[i] = num % 10 + 48;
	i++;
	str[i] = '\0';
	return (i);
}
*/