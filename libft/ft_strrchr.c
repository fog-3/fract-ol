/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:05:44 by fernando          #+#    #+#             */
/*   Updated: 2023/12/01 19:58:10 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			res = (char *)s;
		++s;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (res);
}

/* int main(void)
{
	char    str[] = "Vamooaoo";
	int     n = 97;
	
	printf("%s\n", ft_strrchr(str, n));
	printf("%s\n", strrchr(str, n));
	return (0);
} */
