/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:48:19 by hferjani          #+#    #+#             */
/*   Updated: 2022/06/07 14:37:08 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexa_len(unsigned long long int n)
{
	size_t	len;

	len = (n == 0);
	while (n)
	{
		n /= 16;
		len ++;
	}
	return (len);
}

void	hexa_pourlep(unsigned long long int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		hexa_pourlep(n / 16);
	}
	ft_putchar(base[n % 16]);
}

void	hexa_pourlexcapital(unsigned long long int n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n > 15)
	{
		hexa_pourlexcapital(n / 16);
	}
	ft_putchar(base[n % 16]);
}

size_t	ft_print_x(unsigned int n, char c)
{
	if (c == 'x')
		hexa_pourlep(n);
	if (c == 'X')
		hexa_pourlexcapital(n);
	return (ft_hexa_len(n));
}

size_t	ft_print_ptr(unsigned long long int nb)
{	
	if (nb == 0)
		return (ft_putstr_pour_printf("(nil)"));
	write(1, "0x", 2);
	hexa_pourlep(nb);
	return (ft_hexa_len(nb) + 2);
}
