/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/02/10 10:36:41 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Reproduce el comportamiento de strncmp (man strncmp) */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_strncmp("abc", "abd", 2));
	printf("%d\n", ft_strncmp("abc", "abd", 3));
	return (0);
}
*/
