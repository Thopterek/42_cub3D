/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:26:17 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/10 12:45:19 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	cc;
	unsigned char	*str;

	cc = 0;
	str = (unsigned char *)s;
	while (cc < n)
	{
		if (str[cc] == (unsigned char)c)
		{
			return ((unsigned char *)(&str[cc]));
		}
		cc++;
	}
	return (NULL);
}

// int main (void)
// {
// 	char * pch;
// 	char str[] = "Example string";
// 	pch = (char*) memchr (str, 'p', 5);
// 	printf("This is OriGinal\n");
// 	if (pch!=NULL)
// 		printf ("'p' found at position %ld.\n", pch-str+1);
// 	else
// 		printf ("'p' not found.\n");
// 	char * tmp;
// 	char copy[] = "Example string";
// 	printf("This is my FT\n");
// 	tmp = (char*) ft_memchr (copy, 'p', 5);
// 	if (tmp!=NULL)
// 		printf ("'p' found at position %ld.\n", tmp-copy+1);
// 	else
// 		printf ("'p' not found.\n");
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};
// 	char *new_test;
// 	new_test = memchr(s, 0, 0);
// 	printf("This is OriGinal\n");
// 	if (new_test!=NULL)
// 		printf ("'0' found at position %ld.\n", new_test-s+1);
// 	else
// 		printf ("'0' not found.\n");
// 	char n_s[] = {0, 1, 2 ,3 ,4 ,5};
// 	char *newest;
// 	newest = ft_memchr(n_s, 0, 0);
// 	printf("This is my FT\n");
// 	if (newest!=NULL)
// 		printf ("'0' found at position %ld.\n", newest-n_s+1);
// 	else
// 		printf ("'0' not found.\n");
//   return 0;
// }