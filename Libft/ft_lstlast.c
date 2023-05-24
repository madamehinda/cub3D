/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:50:28 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/23 12:27:33 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*elem;

	if (lst == NULL)
		return (NULL);
	elem = lst;
	while (elem->next != NULL)
	{
		elem = elem->next;
	}
	return (elem);
}
