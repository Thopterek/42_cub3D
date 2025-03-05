/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:52:14 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/11 08:51:48 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cc;
	size_t	tmp;

	cc = 0;
	tmp = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)(haystack));
	while (haystack[cc] != '\0' && cc < len)
	{
		tmp = 0;
		if (haystack[cc] == needle[tmp])
		{
			while (haystack[cc + tmp] == needle[tmp]
				&& haystack[cc + tmp] != '\0' && (cc + tmp) < len)
				tmp++;
			if (tmp == ft_strlen(needle))
				return ((char *)(&haystack[cc]));
		}
		cc++;
	}
	return (NULL);
}

// #include <string.h>
// int main(void)
// {
// 	const char* haystack = "Those are words";
// 	const char* needle = "are";
// 	char n_haystack[30] = "aaabcabcd";
// 	unsigned int i = 20;
// 	printf("This is my FT\n%s\n", ft_strnstr(haystack, needle, i));
// 	printf("This is OriGinal\n%s\n", strnstr(haystack, needle, i));

// 	printf("This is my FT\n%s\n", ft_strnstr(n_haystack, "cd", 8));
// 	printf("This is OriGinal\n%s\n", strnstr(n_haystack, "cd", 8));
// }