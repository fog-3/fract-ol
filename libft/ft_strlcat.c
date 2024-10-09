/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:34:39 by fosuna-g          #+#    #+#             */
/*   Updated: 2023/12/04 12:53:45 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l_dest;
	size_t	size_src;

	l_dest = ft_strlen(dest);
	i = l_dest;
	size_src = ft_strlen(src);
	j = 0;
	if (l_dest >= size)
	{
		return (size_src + size);
	}
	while (src[j] != '\0' && j < (size - l_dest - 1))
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (l_dest + size_src);
}

/* int	main(void)
{
	char			s[] = "the cake is a lie !";
	char			d[] = "there is no stars in the sky";
	unsigned int	n1;
	unsigned int	n2;
	char			src[] = "the cake is a lie !";
	char			dst[] = "there is no stars in the sky";

	n1 = ft_strlcat(d, s, 20);
	printf("%s => tiene (%i) caracteres\n", d, n1);
	n2 = strlcat(dst, src, 20);
	printf("%s => tiene (%i) caracteres", dst, n2);
	return (0);
} */
