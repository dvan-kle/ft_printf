/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_address.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 18:30:24 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/27 12:46:01 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"

static int	ft_puthnbr(unsigned long nb)
{
	if (nb > 15)
	{
		ft_puthnbr(nb / 16);
		ft_puthnbr(nb % 16);
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

static int	h_len(unsigned long nb)
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

int	ft_address(void *p)
{
	unsigned long	nb;

	if (!p)
		return (ft_putstr("0x0\0"));
	nb = (unsigned long)p;
	if (nb == 0)
		return (ft_putchar('0'));
	if (ft_putstr("0x") == -1)
		return (-1);
	if (ft_puthnbr(nb) == -1)
		return (-1);
	return (h_len(nb) + 2);
}
