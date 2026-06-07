/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 10:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/06/06 10:00:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Aplica una funcion a cada caracter de la string original. */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

static void to_upper_i(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

int main(void)
{
    char text[] = "hola";

    ft_striteri(text, to_upper_i);
    printf("%s\n", text);
    return (0);
}
*/
