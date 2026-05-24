/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:38:12 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/24 16:47:57 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	p;
	char			*l;
	int				f;

	f = 0;
	l = ((char *)s);
	p = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == p)
		{
			l = ((char *)s);
			f = 1;
		}
		s++;
	}
	if (p == '\0')
		return ((char *)s);
	if (f == 0)
		return (NULL);
	return (l);
}
