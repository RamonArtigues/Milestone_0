/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/02/10 11:10:58 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Convierte el principio del string str en un int */
/* Gestiona espacios, signos + y - multiples */

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_atoi("  ---+--+1234ab567"));
	printf("%d\n", ft_atoi("42"));
	return (0);
}
*/
