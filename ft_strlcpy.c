/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:30:26 by rartigue          #+#    #+#             */
/*   Updated: 2026/02/04 16:43:49 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*
int	main(void) 
{
	char			source[] = "Holaaa perrro!";
	char			destination[8];
	unsigned int	copied 
	= ft_strlcpy(destination, source, sizeof(destination));
	printf("Cadena: %s\n", destination);
	printf("Longitut: %u\n", copied);
	return (0);
}
*/
