/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:02:56 by fernando          #+#    #+#             */
/*   Updated: 2023/12/16 23:19:31 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nuevalista;

	nuevalista = (t_list *)malloc(sizeof(t_list));
	if (!nuevalista)
		return (0);
	nuevalista->content = content;
	nuevalista->next = NULL;
	return (nuevalista);
}
