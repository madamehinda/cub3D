/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:15:54 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/20 16:28:19 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && (*str != c))
	{
		if (*str == (char)c)
			return ((char *)str);
	str++;
	}
	if (*str == c)
		return ((char *)str);
	return (0);
}

/* La fonction strchr() renvoie un pointeur sur 
la première occurrence du caractère c dans la chaîne s. */

/*int main()
{
	const char str[] = "tripouille";

	printf("%s \n", ft_strchr(str, 't')); 
	printf("%s \n\n", strchr(str, 't')); 

	printf("%s \n", ft_strchr(str, 'l'));  
	printf("%s \n\n", strchr(str, 'l'));  
	
	printf("%s \n", ft_strchr(str, 'z')); 
	printf("%s \n\n", strchr(str, 'z')); 
	
	printf("%s \n", ft_strchr(str, 0));
	printf("%s \n\n", strchr(str, 0));
	
	printf("%s \n", ft_strchr(str, 'c' + 256));
	printf("%s \n\n", strchr(str, 'c' + 256));
	return (0);
}*/
