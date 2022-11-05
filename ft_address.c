/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_address.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 18:30:24 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/11/05 13:26:45 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthexa(unsigned long nb)
{
	if (nb > 15)
	{
		puthexa(nb / 16);
		puthexa(nb % 16);
	}
	else
	{
		if (nb < 10)
		{
			ft_putchar(nb + '0');
		}
		else
		{
			ft_putchar(nb - 10 + 'a');
		}
	}
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

int	ft_address(void	*p)
{
	unsigned long	nb;

	nb = (unsigned long)p;
	ft_putstr("0x");
	if (!p)
		return (ft_putchar('0') + 2);
	puthexa(nb);
	return (h_len(nb) + 2);
}
