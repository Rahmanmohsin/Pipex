/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:57:30 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/20 14:08:58 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while ((*lst) != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = temp;
	}
}
