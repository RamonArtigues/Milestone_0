/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:51:10 by rartigue          #+#    #+#             */
/*   Updated: 2026/05/24 16:55:34 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Reserva memoria inicializada a cero para varios elementos. */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	ft_bzero(ptr, size);
	return (ptr);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *nums;

    nums = (int *)ft_calloc(3, sizeof(int));
    if (!nums)
        return (1);
    printf("%d %d %d\n", nums[0], nums[1], nums[2]);
    free(nums);
    return (0);
}
*/
