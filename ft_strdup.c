/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:44:38 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/19 00:00:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cp;
	size_t	size;
	size_t	i;

	size = ft_strlen(src);
	cp = (char *)malloc(size + 1);
	if (!cp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
