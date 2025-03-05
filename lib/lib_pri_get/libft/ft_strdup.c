/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:07:25 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/15 12:16:38 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*tmp;
	unsigned int	cc;
	unsigned int	sl;

	cc = 0;
	sl = ft_strlen(s1);
	tmp = ft_calloc(sl + 1, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (s1[cc] != '\0')
	{
		tmp[cc] = s1[cc];
		cc++;
	}
	tmp[cc] = '\0';
	return (tmp);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char	*og_str = "Good morning";
// 	char	*my_ft = ft_strdup(og_str);
// 	char	*og_dup = strdup(og_str);
// 	printf("My function:\n%s\n", my_ft);
// 	printf("OriGinal function:\n%s\n", og_dup);
// 	free(my_ft);
// 	free(og_dup);
// }