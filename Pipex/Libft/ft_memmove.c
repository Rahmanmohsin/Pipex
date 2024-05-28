/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:41:12 by mohrahma          #+#    #+#             */
/*   Updated: 2024/03/20 14:14:54 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*dst_add;

	dst_add = dst;
	if (dst < src)
	{
		while (len > 0)
		{
			*(char *)dst_add++ = *(char *)src++;
			len--;
		}
	}
	else if (dst > src)
	{
		dst_add += len;
		src += len;
		while (len > 0)
		{
			*(char *)--dst_add = *(char *)--src;
			len--;
		}
	}
	return (dst);
}

// int main() 
// { 
//     char str1[] = "Geeks"; // Array of size 100 
//     char str2[] = "Quiz"; // Array of size 5 
//     puts("str1 before memmove "); 
//     puts(str1); 
//     /* Copies contents of str2 to sr1 */
//     ft_memmove(str1, str2, sizeof(str2)); 
//     puts("\nstr1 after memmove "); 
//     puts(str1); 
//     return 0; 
// }