/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 13:21:39 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/11/04 19:43:41 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	find_format(char c, va_list list)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_putchar(va_arg(list, int));
	else if (c == 's')
		length += ft_putstr(va_arg(list, char *));
	else if (c == 'p')
		length += ft_address(va_arg(list, void *));
	else if (c == 'd' || c == 'i')
		length += ft_int(va_arg(list, int));
	else if (c == 'u')
		length += ft_uns_int(va_arg(list, unsigned int));
	else if (c == 'x')
		length += ft_hexa(va_arg(list, unsigned int), c);
	else if (c == 'X')
		length += ft_hexa(va_arg(list, unsigned int), c);
	else if (c == '%')
		length += ft_putchar('%');
	else if (c == '\0')
		return (0);
	else
		length++;
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	list;

	va_start(list, str);
	length = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			length += find_format(str[i + 1], list);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			length++;
		}
		if (str[i] != '\0')
			i++;
	}
	return (va_end(list), length);
}
