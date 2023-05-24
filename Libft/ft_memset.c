/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:04:36 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/12 14:50:41 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}
/*La fonction memset() remplit les n premiers octets de la zone mémoire 
pointée par s avec l'octet c.  */

/*int main(void)
 {
	char str[50];

	strcpy(str,"This is string.h library function");
   puts(str);

   memset(str,'$',7);
   puts(str);
	ft_memset(str,'$',7);
	puts(str);
   
   return(0);
}*/
