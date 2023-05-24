/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hferjani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:03:04 by hferjani          #+#    #+#             */
/*   Updated: 2022/05/20 16:30:02 by hferjani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	int		t;
	char	*str;
	char	*ss1;

	size = 0;
	t = 0;
	ss1 = (char *)s1;
	while (ss1[size] != '\0')
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	else
	{
		while (t < size)
		{
			str[t] = ss1[t];
			t++;
		}
		str[t] = '\0';
	}
	return (str);
}
/*La fonction strdup() renvoie un pointeur sur une nouvelle chaîne de 
caractères qui est dupliquée depuis s.
La mémoire occupée par cette nouvelle chaîne est obtenue en appelant
malloc(3), et peut (doit) donc être libérée avec free(3).*/
/*int main(int ac, char **av)
{
    char *original;
    char *copie;

    if (ac == 2)
    { 

    original = strdup(av[1]);
    copie = ft_strdup(av[1]);

    printf("%s\n%s\n", original, copie);
    }
    return (0);
}*/
