/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_funcs.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:35:30 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/11/04 19:20:22 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_int(int nb)
{
	char	*ptr;
	int		i;

	ptr = ft_itoa(nb);
	if (!ptr)
		return (0);
	i = ft_putstr(ptr);
	free(ptr);
	return (i);
}
