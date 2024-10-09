/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:12:27 by fernando          #+#    #+#             */
/*   Updated: 2023/12/03 19:35:30 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(char *res, int n, int i, int size)
{
	if (n == -2147483648)
	{
		res[size] = '8';
		size--;
		n /= 10;
	}
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
		i++;
	}
	while ((size + 1) > i)
	{
		res[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

static void	is_neg(int n, int *size, int *i)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			*size += 1;
			*i /= 10;
		}
		*size += 1;
		*i *= -1;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*res;
	int		i;

	size = 0;
	i = n;
	is_neg(n, &size, &i);
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	if (size == 0)
		size = 1;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	ft_putnbr(res, n, i, size - 1);
	res[size] = '\0';
	return (res);
}

/* int	main(void)
{
	int	n;

	n = 2147483647;
	printf("%s\n", ft_itoa(n));
	return (0);
} */
