/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:45:43 by fernando          #+#    #+#             */
/*   Updated: 2023/11/29 16:16:34 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* int main(void)
{
	char str[] = "hola que ase";
	
	printf("Longitud c: %lu\n", ft_strlen(str));
	printf("Longitud c: %lu\n", strlen(str));
	return (0);
} */
