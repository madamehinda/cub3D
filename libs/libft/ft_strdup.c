/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:22 by imraoui           #+#    #+#             */
/*   Updated: 2023/06/30 15:22:14 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		src;
	char	*dest;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	src = ft_strlen(s) + 1;
	dest = malloc(src * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strddup(const char *s)
{
	int		src;
	char	*dest;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	src = ft_strlen(s);
	dest = malloc(src * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(const char *s, int len)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
