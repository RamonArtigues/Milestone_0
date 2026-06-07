/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 10:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/06/06 10:00:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Crea una string nueva aplicando una funcion a cada caracter. */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

static char add_one(unsigned int i, char c)
{
    (void)i;
    return (c + 1);
}

int main(void)
{
    char *text;

    text = ft_strmapi("abc", add_one);
    if (!text)
        return (1);
    printf("%s\n", text);
    free(text);
    return (0);
}
*/
