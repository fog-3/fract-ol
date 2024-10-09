/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:17:41 by fernando          #+#    #+#             */
/*   Updated: 2023/12/01 12:20:12 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)&big[i]);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len && little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	const char *largestring = "MZIRIBMZIRIBMZE123";
	const char *smallstring = "MZIRIBMZE";
	char	*ptr1;
	char	*ptr2;

	ptr1 = ft_strnstr(largestring, smallstring, 9);
	ptr2 = strnstr(largestring, smallstring, 9);
	printf("Mi funcion: %s\n", ptr1);
	printf("Funcion original: %s\n", ptr2);
	return (0);
} */
