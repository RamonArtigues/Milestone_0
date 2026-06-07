/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:33:42 by rartigue          #+#    #+#             */
/*   Updated: 2026/06/06 10:45:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Pone a cero un bloque de memoria. */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

/*
#include <stdio.h>

int main(void)
{
    char text[5] = "hola";

    ft_bzero(text, 2);
    printf("%d\n", text[0]);
    printf("%d\n", text[1]);
    return (0);
}
*/
