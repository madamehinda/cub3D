/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:00:04 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/17 15:20:01 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	unsigned int	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	if (destsize == 0)
		return (i);
	i = 0;
	while (src[i] && i < destsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}

/*void test(int size)
{ 
	char string[] = "Hello there, Venus";
	char buffer[19];
	int r;
	int r2;

	r = strlcpy(buffer, string, size);
	r2 = ft_strlcpy(buffer, string, size);

printf("original: '%s' into '%s', length %d\n",string,buffer,r);
printf("mafonction: '%s' into '%s', length %d\n", string, buffer, r2);
}

int main ()
{
	test(19);
	test(10);
	test(1);
	test(0);

return(0);
}*/
