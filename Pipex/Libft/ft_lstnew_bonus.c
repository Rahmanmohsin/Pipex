/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:41:09 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/18 14:50:51 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*address;

	address = malloc(sizeof(t_list));
	if (!(address))
		return (NULL);
	address->content = content;
	address->next = NULL;
	return (address);
}
