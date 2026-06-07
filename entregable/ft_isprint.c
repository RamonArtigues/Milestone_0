/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/18 00:00:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Resumen: Comprueba si el caracter es imprimible. */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_isprint(' '));
    printf("%d\n", ft_isprint('\n'));
    return (0);
}
*/
