/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:58:40 by rartigue          #+#    #+#             */
/*   Updated: 2026/06/06 10:45:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Copia memoria de un origen a un destino sin solape. */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*sour;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	sour = (const unsigned char *)src;
	while (n > 0)
	{
		*dest = *sour;
		dest++;
		sour++;
		n--;
	}
	return (dst);
}

/*
#include <stdio.h>

int main(void)
{
    char src[] = "Hola";
    char dst[5];

    ft_memcpy(dst, src, 5);
    printf("%s\n", dst);
    return (0);
}
*/
