/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:43:13 by mohrahma          #+#    #+#             */
/*   Updated: 2023/12/06 00:43:13 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mem_calc(int n)
{
	int		sig_fig;

	sig_fig = 1;
	if (n < 0)
	{
		n = n * -1;
		sig_fig++;
	}
	while (n > 9)
	{
		n = n / 10;
		sig_fig++;
	}
	return (sig_fig);
}

char	*ft_itoa(int n)
{
	int		mem_space;
	char	*result;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	mem_space = ft_mem_calc(n);
	result = malloc(mem_space + 1);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}
	result[mem_space] = '\0';
	while (--mem_space > -1)
	{
		result[mem_space] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
