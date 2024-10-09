/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:25:05 by fernando          #+#    #+#             */
/*   Updated: 2023/11/29 16:15:32 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* int main(void)
{
	char    c;
	
	c = '9';
	if (ft_isdigit(c))
		write(1, "True\n", 5);
	else
		write(1, "False\n", 6);
	return (0);
} */
