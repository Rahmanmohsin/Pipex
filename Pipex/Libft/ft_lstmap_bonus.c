/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:29:00 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/19 13:15:56 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*address;
	void	*f_res;

	result = NULL;
	if (!(lst || f))
		return (NULL);
	while (lst != NULL)
	{
		f_res = f(lst->content);
		address = ft_lstnew(f_res);
		if (!address)
		{
			del(f_res);
			ft_lstclear(&address, del);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, address);
		lst = lst->next;
	}
	return (result);
}
