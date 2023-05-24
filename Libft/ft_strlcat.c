/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:14:14 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/17 15:57:22 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	i = 0;
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size == 0 || dest_size >= size)
		return (src_size + size);
	while (src[i] && (i < size - dest_size -1))
	{
		dest[i + dest_size] = src[i];
		i++;
	}
	dest[i + dest_size] = '\0';
	return (dest_size + src_size);
}

/*int	main ()
{
	char dest[30] = "madamehindaferjani";
	char src[] = "hinda";
	printf("%d\n",ft_strlcat(dest, src, 5));
	return(0);
}*/
