/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:59:52 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/23 13:01:18 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))

{
	t_list	*newlst;
	t_list	*tmp;

	newlst = 0;
	while (lst)
	{
		tmp = ft_lstnew((f)(lst -> content));
		if (!tmp)
		{
			ft_lstdelone(tmp, del);
			return (0);
		}
		ft_lstadd_back(&newlst, tmp);
		tmp = tmp -> next;
		lst = lst -> next;
	}
	return (newlst);
}
