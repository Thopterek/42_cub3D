/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:47:55 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/14 08:12:57 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// IT HAS TO BE DONE ONLY ONCE FROM FRONT 
// AND ONLY ONCE FROM THE BACK set[i] i < len(set)

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	front;
	size_t	back;
	size_t	cc;

	if (s1 == NULL || set == NULL)
		return (NULL);
	front = 0;
	back = 0;
	while (s1[front] != '\0' && ft_strchr(set, s1[front]) != NULL)
		front++;
	while (back < ft_strlen(s1) - front
		&& ft_strchr(set, s1[ft_strlen(s1) - back - 1]) != NULL)
		back++;
	cc = (ft_strlen(s1) - front - back);
	if (cc == 0)
		return (ft_calloc(1, sizeof(char)));
	trim = ft_calloc(cc + 1, sizeof(char));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, &s1[front], (ft_strlen(s1) - front - back) + 1);
	return (trim);
}

// int main(void)
// {
// 	char *s1 = "ababc John Arnold cba";
// 	char *set = "abc";
// 	char *empty = "";
// 	char *trim_one = ft_strtrim(s1, set);
// 	char *trim_two = ft_strtrim(empty, set);
// 	printf("Original string: '%s'\n", s1);
// 	printf("My FT trimmed set abc: '%s'\n", trim_one);
// 	printf("My FT trimmed empty string: '%s'\n", trim_two);
// 	free(trim_one);
// 	free(trim_two);
// }
