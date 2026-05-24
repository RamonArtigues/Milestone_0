/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:13:19 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/24 15:43:32 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_copy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	ft_copy(dst, src, n);
	return (dst);
}

void	ft_copy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sour;

	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	if (dst < src)
	{
		while (n > 0)
		{
			*dest = *sour;
			dest++;
			sour++;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			dest[n - 1] = sour[n - 1];
			n--;
		}
	}
}