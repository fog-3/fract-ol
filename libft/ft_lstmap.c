/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:00:22 by fernando          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/03/10 13:57:47 by fernando         ###   ########.fr       */
=======
/*   Updated: 2024/02/13 09:34:04 by fernando         ###   ########.fr       */
>>>>>>> 57abc1291bc7f26d69390fd30bdc2a6abcfde52b
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		cnt;
	t_list	*res;
	t_list	*aux;

	if (!lst)
		return (0);
	cnt = ft_lstsize(lst);
	aux = 0;
	res = NULL;
	while (cnt > 0)
	{
		aux = ft_lstnew(NULL);
		if (!aux)
		{
			ft_lstclear(&aux, del);
			ft_lstclear(&res, del);
			return (0);
		}
		aux->content = f(lst->content);
		ft_lstadd_back(&res, aux);
		lst = lst->next;
		cnt--;
	}
	return (res);
}
