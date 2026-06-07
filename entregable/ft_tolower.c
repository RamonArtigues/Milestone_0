/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/18 00:00:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Resumen: Convierte una letra mayuscula a minuscula. */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
#include <stdio.h>

int main(void)
{
    printf("%c\n", ft_tolower('H'));
    printf("%c\n", ft_tolower('h'));
    return (0);
}
*/
