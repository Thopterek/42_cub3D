/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:44:56 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/11 14:47:25 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*first;
	char	*sec;
	size_t	cc;

	first = (char *)s1;
	sec = (char *)s2;
	cc = ft_strlen(first) + ft_strlen(sec);
	new = ft_calloc(cc + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, first, ft_strlen(first) + 1);
	ft_strlcat(new, sec, cc + 1);
	return (new);
}

// cc -Wall -Werror -Wextra ft_strjoin.c ft_calloc.c 
// ft_strlen.c ft_bzero.c ft_strlcpy.c ft_strlcat.c
// #include <string.h>
// int main(void)
// {
// 	char *test_one = "John ";
// 	char *second_test = "short";
// 	char *string_two = "look 14 chars";
// 	char *tmp_join;
// 	char *sec_join;
// 	tmp_join = ft_strjoin(test_one, string_two);
// 	sec_join = ft_strjoin(second_test, string_two);
// 	printf("This is how string looks like:\n%s\n", tmp_join);
// 	printf("This is with test 2:\n%s\n\n", sec_join);
// 	free (tmp_join);
// 	free (sec_join);
// }