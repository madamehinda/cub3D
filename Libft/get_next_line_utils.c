/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:38:09 by hferjani          #+#    #+#             */
/*   Updated: 2022/10/29 11:30:20 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}*/

/*char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while ((*s != '\0') && (*s != c))
	{
		if (*s == ((char)c))
			return ((char *)s);
		s++;
	}
	if (*s == ((char)c))
		return ((char *)s);
	return (NULL);
}*/

void	ft_line(char *line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i])
	{
		buffer[j] = line[i];
		line[i] = '\0';
		i++;
		j++;
	}
	buffer[j] = '\0';
}

/*char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}*/

/*char *ft_strjoin(char *s1, char *s2)
{
	int len;
	int i;
	char *str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			{
				str[i] = s1[i];
				i++;
			}
		else
		{
			str[i] = s2[i - ft_strlen(s1)];
			i++;
		}
	}
	str[i] = '\0';
	free(s1);
	return (str);
}*/
