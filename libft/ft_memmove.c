/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:29:00 by fernando          #+#    #+#             */
/*   Updated: 2023/12/04 11:58:01 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;

	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}

/* int	main(void)
{
	char	dest[] = "locooo";
	char	src[] = "vamos";
	char	dest1[] = "locooo";
	char	src1[] = "vamos";

	printf ("%s\n", (char *)ft_memmove((void *)src, (void *)dest, 6));
	printf ("%s\n", (char *)memmove((void *)src1, (void *)dest1, 6));
	return (0);
} */
