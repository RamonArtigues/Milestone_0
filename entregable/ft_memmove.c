/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:13:19 by rartigue          #+#    #+#             */
/*   Updated: 2026/06/06 10:45:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Copia memoria permitiendo solape entre origen y destino. */

/* Copia de izquierda a derecha cuando aún no hay riesgo de pisar datos. */
static void	copy_forward(unsigned char *dst, const unsigned char *src, size_t n)
{
	while (n > 0)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
}

/* Copia desde el final cuando origen y destino se solapan. */
static void	copy_backward(unsigned char *dst,
			const unsigned char *src, size_t n)
{
	while (n > 0)
	{
		dst[n - 1] = src[n - 1];
		n--;
	}
}

/* Hace una copia segura incluso cuando src y dst se pisan entre sí. */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*sour;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	sour = (const unsigned char *)src;
	if (dest < sour)
		copy_forward(dest, sour, n);
	else
		copy_backward(dest, sour, n);
	return (dst);
}

/*
#include <stdio.h>

int main(void)
{
    char text[] = "123456";

    ft_memmove(text + 2, text, 4);
    printf("%s\n", text);
    return (0);
}
*/
