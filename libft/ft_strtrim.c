/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:46:26 by fernando          #+#    #+#             */
/*   Updated: 2023/12/04 11:25:33 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	start;
	size_t	cont;

	cont = 0;
	if (!s1 || !set)
		return (0);
	while (s1[cont] && ft_isset(s1[cont], set) == 1)
		cont++;
	start = cont;
	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_isset(s1[i], set) == 1)
	{
		cont++;
		i--;
	}
	i = ft_strlen(s1);
	res = ft_substr(s1, start, (i - cont));
	return (res);
}

/* int	main(void)
{
	//char *s1 = "  \t \t \n   \n\n\n\t";
 	//char *s2 = "abc ";

	printf("Salida de mi fnc: %s\n", ft_strtrim("", ""));
	//printf("Salida esperada: %s\n", s2);
	return (0);
} */
