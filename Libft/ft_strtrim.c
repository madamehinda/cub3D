/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:57:06 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/20 14:54:16 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	while (ft_strchr(s2, *s1) && *s1 != '\0')
		s1++;
	len = ft_strlen((char *)s1);
	while (ft_strchr(s2, s1[len]) && len != 0)
		len--;
	return (ft_substr((char *)s1, 0, len + 1));
}
/*Alloue (avec malloc(3)) et retourne une copie de
la chaîne ’s1’, sans les caractères spécifiés
dans ’set’ au début et à la fin de la chaîne de
caractères.*/