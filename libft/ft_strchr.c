/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:00:53 by fernando          #+#    #+#             */
/*   Updated: 2023/12/01 13:24:16 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (res[i])
	{
		if (res[i] == (char)c)
			return ((char *)&res[i]);
		i++;
	}
	if (res[i] == (char)c)
		return ((char *)&res[i]);
	return (0);
}

/* int main(void)
{
	char    str[] = "teste";
	int     n = 1024;

	printf("Mi funcion: %s\n", ft_strchr(str, n));
	printf("Fnc origin: %s\n", strchr(str, n));
	return (0);
} */
