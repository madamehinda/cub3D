/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:46:08 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/23 12:27:04 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nouvelelement;

	nouvelelement = malloc(sizeof(t_list));
	if (!nouvelelement)
		return (NULL);
	nouvelelement->content = content;
	nouvelelement->next = NULL;
	return (nouvelelement);
}
