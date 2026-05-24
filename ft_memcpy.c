/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:58:40 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/24 15:32:58 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sour;

	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	while (n > 0)
	{
		*dest = *sour;
		dest++;
		sour++;
		n--;
	}
	return (dst);
}