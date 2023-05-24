/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:06:02 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/20 15:55:46 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
			i++;
	return (i);
}

static size_t	ft_wordcounter(const char *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
				i++;
		if (s[i])
				counter++;
		while (s[i] && s[i] != c)
				i++;
	}
	return (counter);
}

static char	*ft_strsplit(const char *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	split = malloc((ft_wordcounter(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_wordcounter(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			split[j] = ft_strsplit (s + i, c);
			j++;
		}
		while (s[i] && s[i] != c)
				i++;
	}
	split[j] = (NULL);
	return (split);
}
/*Alloue (avec malloc(3)) et retourne un tableau
de chaînes de caractères obtenu en séparant ’s’ à
l’aide du caractère ’c’, utilisé comme délimiteur.
Le tableau doit être terminé par NULL.*/