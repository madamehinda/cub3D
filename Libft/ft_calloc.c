/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:17:28 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/24 10:17:56 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (count && (count * size / count) != size)
		return (NULL);
	dest = malloc(count * size);
	if (!dest)
		return (NULL);
	ft_bzero((char *)dest, count * size);
	return ((char *)dest);
}
