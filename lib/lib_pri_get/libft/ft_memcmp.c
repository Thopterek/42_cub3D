/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:47:17 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/10 08:52:44 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cc;
	size_t			one;
	unsigned char	*str;
	unsigned char	*com;

	cc = 0;
	one = 1;
	str = (unsigned char *)s1;
	com = (unsigned char *)s2;
	if (n == 0)
		return (n);
	while (cc < n)
	{
		if (str[cc] != com[cc])
			return (str[cc] - com[cc]);
		if (cc == n - one)
			return (str[cc] - com[cc]);
		cc++;
	}
	return (str[cc] - com[cc]);
}

// #include <string.h>
// int main(void)
// {
//     char buffer1[] = "asdf9";
//     char buffer2[] = "asdfg";

//     int n;

//     n=memcmp (buffer1, buffer2, sizeof(buffer1));
// 	printf("This is OriGinal\n");

//     if (n>0) printf ("'%s' is greater than '%s'.\n",buffer1,buffer2);
//     else if (n<0) printf ("'%s' is less than '%s'.\n",buffer1,buffer2);
//     else printf ("'%s' is the same as '%s'.\n",buffer1,buffer2);

//     char copy1[] = "asdf9";
//     char copy2[] = "asdfg";

//     int fc;

//     fc=ft_memcmp (copy1, copy2, sizeof(copy1));
// 	printf("This is my FT\n");

//     if (fc>0) printf ("'%s' is greater than '%s'.\n",copy1,copy2);
//     else if (fc<0) printf ("'%s' is less than '%s'.\n",copy1,copy2);
//     else printf ("'%s' is the same as '%s'.\n",copy1,copy2);

//     return 0;
// }