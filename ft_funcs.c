/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_funcs.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:35:30 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/27 14:20:27 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_int(int nb)
{
	char	*ptr;
	int		i;

	ptr = ft_itoa(nb);
	if (!ptr)
		return (-1);
	i = ft_putstr(ptr);
	free(ptr);
	return (i);
}
