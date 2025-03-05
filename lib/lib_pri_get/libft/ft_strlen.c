/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:59:13 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/10 08:53:32 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char	*s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

// #include <string.h>
// #include <stdlib.h>
// int main(void)
// {
// 	char* skrr = "five5";
// 	char* zero = "";
// 	printf("This is my FT\n%zu\n", ft_strlen(skrr));
// 	printf("This is my FT\n%zu\n", ft_strlen(zero));
// 	printf("This is OriGinal\n%lu\n", strlen(skrr));
// 	printf("This is OriGinal\n%lu\n", strlen(zero));
// }