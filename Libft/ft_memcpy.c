/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:21:24 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/17 15:11:45 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"        

void	*ft_memcpy(void *dest, const void *src, size_t n)

{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
/*La fonction memcpy() copie n octets depuis la zone mémoire 
src vers la zone mémoire dest. 
Les deux zones ne doivent pas se chevaucher*/