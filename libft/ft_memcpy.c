/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:12:55 by fosuna-g          #+#    #+#             */
/*   Updated: 2023/12/04 11:31:37 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sourc;
	size_t	i;

	if (!dst && !src)
		return (0);
	dest = (char *)dst;
	sourc = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return ((void *)dest);
}

/* int	main(void)
{
	char	src[] = "hola";
	char	dst[] = "wakala";

	ft_memcpy(dst, src, 4);
	printf("%s\n", dst);
	return (0);
} */
