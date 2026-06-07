/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/18 00:00:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Resumen: Comprueba si el valor esta dentro del ASCII basico. */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_isascii(65));
    printf("%d\n", ft_isascii(200));
    return (0);
}
*/
