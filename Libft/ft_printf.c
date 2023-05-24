/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:31:28 by hferjani          #+#    #+#             */
/*   Updated: 2022/06/07 17:19:59 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

size_t	ft_type_parametre(va_list arg, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr_pour_printf(va_arg(arg, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_pour_printf(va_arg(arg, int)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(arg, unsigned long long int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_x(va_arg(arg, unsigned int), format));
	else if (format == 'u')
		return (ft_putnbr_u(va_arg(arg, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_type_parametre(arg, str[i]);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}

/*int  main()
{
	   char **abc;

abc = NULL;
printf("%%\n");
ft_printf("%%\n");
printf("le caractere est %c ou %c\n", 'b','n');
ft_printf("le caractere est %c ou %c\n", 'b','n');
printf("%c\n", '2');
ft_printf("%c\n", '2');
printf("avec p%p\n", abc);
ft_printf("avec p%p\n", abc);
char *str;
str = "est-ce une string?";
printf("%s\n", str);
ft_printf("%s\n", str);

int age = 10;
int *pointeursurage = &age;

printf("%p\n", pointeursurage);
ft_printf("%p\n", pointeursurage);

printf("%u\n", 2147483647);
ft_printf("%u\n", 2147483647);
  int x = 50;
int *ptr = &x;
printf("The address is: %p \n", ptr);
ft_printf("The address is: %p \n",ptr);

ft_printf ("Characters: %c %c \n", 65,'a');
printf ("Characters: %c %c \n", 65,'a');
ft_printf ("Decimals: %d \n", 197555557);
printf ("Decimals: %d \n", 197555557);
ft_printf ("Some different radices: %d %x  \n", 100, 100);
printf ("Some different radices: %d %x  \n", 100, 100);
ft_printf ("%i%i%i%i%i%i%i\n", 10, 23, -2, 37, 200, -9999, 977779);
printf ("%i%i%i%i%i%i%i\n", 10, 23, -2, 37, 200, -9999, 977779);
ft_printf ("Characters: %c\n", 65);
printf ("Characters: %c\n", 65);
ft_printf ("the password is %x\n", 3735929054u);
printf ("the password is %x\n", 3735929054u);
ft_printf ("the password is %X\n", (unsigned int)3735929054);
printf ("the password is %X\n", (unsigned int)3735929054);
return 0;
 }*/