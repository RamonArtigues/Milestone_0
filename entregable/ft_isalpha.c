/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/18 00:00:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Resumen: Comprueba si el caracter es una letra alfabetica. */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*
#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_isalpha('A'));
    printf("%d\n", ft_isalpha('4'));
    return (0);
}
*/
