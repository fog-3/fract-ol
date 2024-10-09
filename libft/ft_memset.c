/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:48:52 by fernando          #+#    #+#             */
/*   Updated: 2023/11/29 17:26:37 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (len > 0)
	{
		str[i] = c;
		i++;
		len--;
	}
	return (s);
}

/* int	main(void)
{
	char	str[] = "Esto sosyadaofl";

	ft_memset(str, '&', 6);
	memset(str, '&', 6);
	printf("Str ahora es: %s\n", str);
	return (0);
} */
