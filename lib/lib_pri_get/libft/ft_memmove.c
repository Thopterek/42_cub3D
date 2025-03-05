/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:46:11 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/12/10 18:10:46 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*sour;
	unsigned char	*desti;

	sour = (unsigned char *)src;
	desti = (unsigned char *)dst;
	if (len == 0 || dst == src)
		return (dst);
	if (desti < sour || sour + len < desti)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	else
	{
		while (0 < len)
		{
			desti[len - 1] = sour[len - 1];
			len--;
		}
		return (dst);
	}
}

// #include <string.h>
// int main(void)
// {
// 	unsigned char dst[] = "7times7 i kalafior";
// 	unsigned char src[] = " potato";
// 	ft_memmove(dst, src, 7);
// 	printf("Thats mine FT:\n%s\n", dst);
// 	unsigned char original[] = "7times7 i kalafior";
// 	unsigned char ogsource[] = " potato";
// 	memmove(original, ogsource, 7);
// 	printf("Thats OriGinal:\n%s\n", original);
// 	char new_test[] = {67, 68, 67, 68, 69, 0, 45};
// 	ft_memmove(new_test + 1, new_test, 2);
// 	printf("Thats mine FT:\n%s\n", new_test);
// 	char new_test_copy[] = {67, 68, 67, 68, 69, 0, 45};
// 	memmove(new_test_copy + 1, new_test_copy, 2);
// 	printf("Thats mine FT:\n%s\n", new_test_copy);
// }
