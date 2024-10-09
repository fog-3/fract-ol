/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:52:50 by fernando          #+#    #+#             */
/*   Updated: 2023/12/17 17:41:20 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*aux;

	if (!*lst)
		return ;
	aux = *lst;
	while (aux)
	{
		tmp = aux->next;
		ft_lstdelone(aux, del);
		aux = tmp;
	}
	*lst = NULL;
}
