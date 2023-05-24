/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:32:34 by hferjani          #+#    #+#             */
/*   Updated: 2022/11/24 12:14:39 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	ft_type_parametre(va_list arg, const char format);
size_t	ft_putchar(char c);
size_t	ft_putstr_pour_printf(char *str);
size_t	ft_putnbr_pour_printf(int nbr);
size_t	ft_print_ptr(unsigned long long int nb);
void	ft_putnbr_unsigned_int(unsigned int nbr);
size_t	ft_putnbr_u(unsigned int nbr);
size_t	longueur_nbr(long nbr);
void	ft_putnbr(int nbr);
size_t	ft_print_x(unsigned int n, char c);
size_t	ft_hexa_len(unsigned long long int n);
void	hexa_pourlep(unsigned long long int n);
void	hexa_pourlexcapital(unsigned long long int n);

#endif
