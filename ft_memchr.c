/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:45:20 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/24 15:56:45 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*i;

	p = (unsigned char *)&c;
	while (n > 0)
	{
		i = (unsigned char *)s;
		if (*p == *i)
			return (i);
		s++;
		n--;
	}
	return (NULL);
}