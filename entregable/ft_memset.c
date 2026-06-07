/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:38:07 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/24 15:33:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Rellena un bloque de memoria con un byte repetido. */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = (unsigned char)c;
		p++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>

int main(void)
{
    char text[6] = "abcde";

    ft_memset(text, 'X', 3);
    printf("%s\n", text);
    return (0);
}
*/
