/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 07:09:48 by ndziadzi          #+#    #+#             */
/*   Updated: 2025/03/05 15:43:31 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_printf(const char *av, ...);
char	*ft_uns_itoa(unsigned int n);
char	*ft_hex_itoa(unsigned int n, char cc);
char	*ft_ptr_itoa(unsigned long n);
char	*get_next_line(int fd);

#endif