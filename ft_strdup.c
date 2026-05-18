/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:44:38 by rartigue          #+#    #+#             */
/*   Updated: 2026/02/16 18:01:43 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_size(char *str)
{
	int	i;

	i = 0;
	while (str [i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cp;
	int		size;
	int		i;

	i = 0;
	size = ft_size(src);
	cp = (char *)malloc(1 * size + 1);
	while (i < size)
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = ft_strdup("Hola mundo");
	printf("%s\n", str1);
	free(str1);
	str2 = ft_strdup("");
	printf("'%s'\n", str2);
	free(str2);
	return (0);
}
*/
