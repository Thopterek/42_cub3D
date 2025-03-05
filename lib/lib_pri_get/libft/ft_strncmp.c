/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:56:08 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/11 08:37:38 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cc;

	cc = 0;
	if (n == 0)
		return (n);
	while (s1[cc] != '\0' && s2[cc] != '\0')
	{
		if (s1[cc] != s2[cc])
			return ((unsigned char)s1[cc] - (unsigned char)s2[cc]);
		if (cc == n - 1)
			return ((unsigned char)s1[cc] - (unsigned char)s2[cc]);
		cc++;
	}
	return ((unsigned char)s1[cc] - (unsigned char)s2[cc]);
}

// #include <string.h>
// int	main(void)
// {
// 	char *test = "Jonny";
// 	char *copy = "Jonny";
// 	char *diff = "Joke";
// 	printf("%d\n", ft_strncmp(test, copy, 10));
// 	printf("%d\n", ft_strncmp(test, diff, 1));
// 	printf("%d\n", ft_strncmp(test, diff, 3));
// 	printf("This is OriGinal\n%d\n", strncmp(test, copy, 10));
// 	printf("%d\n", strncmp(test, diff, 1));
// 	printf("%d\n", strncmp(test, diff, 3));
// }