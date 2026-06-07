/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/18 00:00:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Resumen: Comprueba si el caracter es un digito decimal. */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_isdigit('7'));
    printf("%d\n", ft_isdigit('a'));
    return (0);
}
*/
