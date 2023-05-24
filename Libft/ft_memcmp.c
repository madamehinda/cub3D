/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:17:32 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/20 16:24:24 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <unistd.h>
#include <stdio.h>
#include <string.h>*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (0);
}
/*La fonction memcmp() compare les n premiers octets 
des zones mémoire s1 et s2. 
Elle renvoie un entier inférieur, égal, ou supérieur 
à zéro, si s1 est respectivement inférieure, 
égale ou supérieur à s2*/

/*int main () 
{
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) 
      printf("str2 is less than str1");
   else if(ret < 0) 
      printf("str1 is less than str2");
   else 
      printf("str1 is equal to str2");
   return(0);
}*/
