/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:22:14 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/24 16:36:36 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Busca la primera aparicion de un caracter en una string. */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	p;

	p = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == p)
			return ((char *)s);
		s++;
	}
	if (p == '\0')
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
    char *found;

    found = ft_strchr("bonjour", 'j');
    if (found)
        printf("%s\n", found);
    return (0);
}
*/
