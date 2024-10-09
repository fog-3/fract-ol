/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:56:22 by fernando          #+#    #+#             */
/*   Updated: 2023/12/02 13:50:11 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		start = ft_strlen(s);
		len = 0;
	}
	size = ft_strlen(s + start);
	if (len > size)
		len = size;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
