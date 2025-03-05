/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:57:53 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/25 16:07:05 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Those are allowed:
// malloc, free, write,
// va_start, va_arg, va_copy, va_end
// Don’t implement the buffer management of the original printf().
// • Your function will be compared against the original printf().
// • You must use the command ar to create your library.
// Using the libtool command is forbidden.
// • %p The void * pointer argument has to be printed in hexadecimal format.

#include "ft_printf.h"
#include "libft/libft.h"

static int	ptr_logic(va_list ac)
{
	void	*a_p;
	char	*str;
	size_t	num;
	ssize_t	check;

	a_p = va_arg(ac, void *);
	str = ft_ptr_itoa((unsigned long)a_p);
	if (str == NULL)
		return (-1);
	check = ft_putstr_fd(str, 1);
	num = ft_strlen(str);
	free(str);
	if (check == -1)
		return (check);
	return (num);
}

static int	num_tab(char cc, va_list ac)
{
	char	*str;
	ssize_t	num;

	str = NULL;
	if (cc == 'i' || cc == 'd')
	{
		str = ft_itoa(va_arg(ac, int));
		if (str == NULL)
			return (-1);
		num = ft_putstr_fd(str, 1);
		if (num == -1)
			return (free(str), num);
		return (num = ft_strlen(str), free(str), num);
	}
	if (cc == 'u')
	{
		str = ft_uns_itoa(va_arg(ac, unsigned int));
		if (str == NULL)
			return (-1);
		num = ft_putstr_fd(str, 1);
		if (num == -1)
			return (free(str), num);
		return (num = ft_strlen(str), free(str), num);
	}
	return (0);
}

static int	px_tab(char cc, va_list ac)
{
	char	*str;
	size_t	num;
	ssize_t	check;

	str = NULL;
	if (cc == 'p')
		return (ptr_logic(ac));
	if (cc == 'x' || cc == 'X')
	{
		str = ft_hex_itoa(va_arg(ac, unsigned int), cc);
		if (str == NULL)
			return (-1);
		check = ft_putstr_fd(str, 1);
		num = ft_strlen(str);
		free(str);
		if (check == -1)
			return (check);
		return (num);
	}
	return (0);
}

static int	tables(char cc, va_list ac)
{
	char	*str;
	ssize_t	check;

	str = NULL;
	if (cc == 'c')
		check = ft_putchar_fd(va_arg(ac, int), 1);
	if (cc == '%')
		check = ft_putchar_fd('%', 1);
	if (check != -1 && (cc == 'c' || cc == '%'))
		return (1);
	if (cc == 's')
	{
		str = va_arg(ac, char *);
		if (str == NULL)
			str = "(null)";
		check = ft_putstr_fd(str, 1);
		if (check != -1)
			return (ft_strlen(str));
	}
	if (cc == 'i' || cc == 'd' || cc == 'u')
		return (num_tab(cc, ac));
	if (cc == 'p' || cc == 'x' || cc == 'X')
		return (px_tab(cc, ac));
	return (check);
}

int	ft_printf(const char *av, ...)
{
	ssize_t	print;
	ssize_t	check;
	va_list	ac;

	va_start(ac, av);
	print = 0;
	while (*av != '\0')
	{
		if (*av == '%')
		{
			av++;
			check = tables(*av, ac);
			print += check;
		}
		else
		{
			check = ft_putchar_fd(*av, 1);
			print++;
		}
		if (check == -1)
			return (-1);
		av++;
	}
	va_end(ac);
	return (print);
}
// make
// gcc ft_printf.c libftprintf.a
// void leaks(void)
// {
// 	system(leaks (libftprintf.a));
// }
// #include <stdio.h>
// int main(void)
// {
// 	char one_c = 'a';
// 	char *string = "Here we go again...";
// 	char *ptr = string;
// 	printf("OriGinal char: %c\n", one_c);
// 	ft_printf("My Function char: %c\n", one_c);
// 	printf("OG prints_p: %%\n");
// 	ft_printf("My FT p_percent: %%\n");
// 	printf("OG string print: %s\n", string);
// 	ft_printf("My FT string: %s\n", string);
// 	printf("OG number: %i\n", 6345903);
// 	ft_printf("Moj numer: %i\n", 6345903);
// 	printf("Unsinged OG: %u\n", (unsigned int)4294967295);
// 	ft_printf("UN my version: %u\n", (unsigned int)4294967295);
// 	printf("OG hex number: %x\n", 6345903);
// 	ft_printf("Mine HEX num: %x\n", 6345903);
// 	printf("OG hex number: %X\n", (int)-6345903);
// 	ft_printf("Mine HEX num: %X\n", (int)-6345903);
// 	printf("OG address of ptr: %p\n", (void *)ptr);
// 	ft_printf("My function &ptr: %p\n", (void *)ptr);
// 	printf("Original MIX: \n%s\n%d %X\n", string, 123, -323);
// 	ft_printf("My FT mixed: \n%s\n%d %X\n", string, 123, -323);
// 	// atexit(leaks);
// 	return (0);
// }