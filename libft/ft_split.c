/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:16:14 by fernando          #+#    #+#             */
/*   Updated: 2023/12/15 17:20:58 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_countwords(char const *s, char c)
{
	int	i;
	int	cntw;
	int	bol;

	i = 0;
	cntw = 0;
	bol = 1;
	while (s[i])
	{
		if (s[i] == c)
			bol = 1;
		else if (bol)
		{
			bol = 0;
			cntw++;
		}
		i++;
	}
	return (cntw);
}

static char	**ft_free(char const **res, int i)
{
	while (i > 0)
	{
		i--;
		free((void *)res[i]);
	}
	free(res);
	return (0);
}

static void	inivar(int *bol, int *st, int *j)
{
	*bol = 1;
	*st = 0;
	*j = 0;
}

static char	**result(char **res, char const *s, char c, int i)
{
	int	bol;
	int	st;
	int	j;

	inivar(&bol, &st, &j);
	while (i < ft_countwords(s, c))
	{
		if (s[j] == c || s[j] == '\0')
		{
			if (!bol)
			{
				res[i] = ft_substr(s, st, j - st);
				if (!res[i])
					return (ft_free((char const **)res, i));
				i++;
			}
			bol = 1;
			st = j + 1;
		}
		else if (bol)
			bol = 0;
		j++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	i = 0;
	if (!s)
		return (0);
	res = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!res)
		return (0);
	return (result(res, s, c, i));
}

/* int	main(void)
{
	const char	*s = "hola hello! ";
	int			i = 0;
	char		**res;
	int			j = 0;

	res = ft_split(s, ' ');
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
} */
