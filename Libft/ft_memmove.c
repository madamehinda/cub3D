/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:49:55 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/12 14:52:17 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)

{
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*La fonction memmove() copie n octets depuis la zone mémoire src vers 
la zone mémoire dest. 
Les deux zones peuvent se chevaucher : la copie se passe comme si 
les octets de src étaient d'abord copiés dans une zone temporaire 
qui ne chevauche ni src ni dest, et les octets sont ensuite copiés 
de la zone temporaire vers dest. */
