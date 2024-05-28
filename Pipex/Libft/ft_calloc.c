/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:52:57 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/20 14:06:01 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*result;

	result = malloc(nitems * size);
	if (!result)
		return (NULL);
	ft_bzero(result, nitems * size);
	return (result);
}
