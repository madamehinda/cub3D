/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_principales.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:07:41 by hferjani          #+#    #+#             */
/*   Updated: 2022/06/07 17:04:32 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr_pour_printf(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putnbr_pour_printf(int nbr)
{
	ft_putnbr(nbr);
	return (longueur_nbr(nbr));
}

void	ft_putnbr_unsigned_int(unsigned int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr_unsigned_int(nbr / 10);
		nbr %= 10;
	}
	ft_putchar(nbr + 48);
}

size_t	ft_putnbr_u(unsigned int nbr)
{
	ft_putnbr_unsigned_int(nbr);
	return (longueur_nbr(nbr));
}

/*int	ft_itoa_base16(int nb)
{
	int	i;
	char *base;

	base = "0123456789abcdef";
	if (nb >15)
		ft_itoa_base16(nb/16);
	if (nb % 16 < 10)
		base[i] = nb%16 + 48;
	else 
		base[i] = nb%16 + 87;
	i++;
	base[i] = '\0';
}*/

/*void	ft_print_upper_hexa(unsigned long long int nb)
{
	char	*base;
	
	base = "0123456789ABCDEF";
	if (nb >= 15)
		ft_print_upper_hexa(nb/16);
	ft_putchar(base[nb%16]);
	
}*/

/*int	check_valide(char *base)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(base);
	i =0;
	if (base[0] == '\0' || len == 1])
		return (0);
	while (base[i] != '\0')
	{
		if base[i] == '-' || base[i] == '+'
				|| base[i] == 127 || base[i] <= 32)
				return (0);
	}
	return(1);
}
int	putnbr_base(int nbr, char *base)
{
	long int	nb;	
	int	base_calcul;
	int error;

	nb = nbr;
	error = check_valide(base);
	base_calcul = ft_strlen(base);
	if (error == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1
		}
		if (nb < i)
			write(1, &base[nb], 1);
			
		if (nb >= i)
		{
			ft_putnbr_base(nb / base_calcul, base);
			ft_putnbr_base(nb % base_calcul, base);
		}
	}
}
*/
