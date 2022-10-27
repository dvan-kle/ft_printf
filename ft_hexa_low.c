/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexa_low.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 16:49:02 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/27 13:35:24 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"

static int	ft_puth(unsigned int nb)
{
	if (nb > 15)
	{
		if (ft_puth(nb / 16) == -1)
			return (-1);
		if (ft_puth(nb % 16) == -1)
			return (-1);
	}
	else
	{
		if (nb < 10)
		{
			if (ft_putchar(nb + '0') == -1)
				return (-1);
		}	
		else
		{
			if (ft_putchar(nb - 10 + 'a') == -1)
				return (-1);
		}
	}
	return (1);
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

int	ft_hexa_low(unsigned int nb)
{
	if (nb == 0)
		return (ft_putchar('0'));
	if (ft_puth(nb) == -1)
		return (-1);
	return (h_len(nb));
}
