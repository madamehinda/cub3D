/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:12:17 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/24 11:22:51 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char *str, const char *find, size_t len, size_t index)
{
	size_t	j;

	j = 0;
	while (find[j] != '\0')
	{
		if (index >= len)
		{
			return (0);
		}
		if (find[j] != str[index])
		{
			return (0);
		}
		index++;
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *strr, const char *find, size_t len)
{
	size_t	index;
	char	*str;

	str = (char *)(strr);
	index = 0;
	if (*find == 0)
		return (str);
	while (str[index] != '\0')
	{
		if (ft_find(str, find, len, index) == 0)
		{
			index++;
		}
		else if (ft_find(str, find, len, index) == 1)
		{
			return (&str[index]);
		}
	}
	return (NULL);
}
