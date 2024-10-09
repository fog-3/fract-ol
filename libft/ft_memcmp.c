/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:03:44 by fernando          #+#    #+#             */
/*   Updated: 2023/12/01 13:50:30 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (i < n)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char    s1[] = "\xff\xaa\xde\xffMACOSX\xff";
	char    s2[] = "\xff\xaa\xde\x02";
	int     res;

	res = ft_memcmp(s1, s2, 8);
	printf("res1: %d\n", res);
	res = memcmp(s1, s2, 8);
	printf("res2: %d\n", res);
	return (0);
} */
