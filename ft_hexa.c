/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 16:49:02 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/11/04 19:21:16 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthexa(unsigned int nb, char format)
{
	if (nb > 15)
	{
		puthexa(nb / 16, format);
		puthexa(nb % 16, format);
	}
	else
	{
		if (nb < 10)
		{
			ft_putchar(nb + '0');
		}	
		else
		{
			if (format == 'X')
				ft_putchar(nb - 10 + 'A');
			if (format == 'x')
				ft_putchar(nb - 10 + 'a');
		}
	}
}

static int	h_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_hexa(unsigned int nb, char format)
{
	if (nb == 0)
		return (ft_putchar('0'));
	puthexa(nb, format);
	return (h_len(nb));
}
