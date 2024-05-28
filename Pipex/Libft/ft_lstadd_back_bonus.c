/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:42:02 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/18 15:43:53 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*address;

	if (!(*lst))
		return (ft_lstadd_front(lst, new));
	else if (!new)
		return ;
	else
	{
		address = ft_lstlast((*lst));
		address->next = new;
	}
}
