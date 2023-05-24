/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:49:03 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/20 14:52:04 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	t;
	size_t	slen;

	t = 0;
	slen = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (NULL);
	while (t < len && start + t < slen)
	{
		ret[t] = s[start + t];
		t++;
	}
	ret[t] = '\0';
	return (ret);
}
/*Alloue (avec malloc(3)) et retourne une chaîne de
caractères issue de la chaîne ’s’.
Cette nouvelle chaîne commence à l’index ’start’ et
a pour taille maximale ’len’.*/