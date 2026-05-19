/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/18 00:00:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if (!needle[0])
		return ((char *)haystack);
	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && i + j < len && haystack[i + j] == needle[j])
			j++;
		if (j == needle_len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
