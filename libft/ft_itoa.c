/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 19:44:14 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/22 22:50:59 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n, int len)
{
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*number(char *ptr, int n, int len)
{
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		ptr[len--] = (n % 10) + 48;
		n = n / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 0;
	len = ft_len(n, len);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	len--;
	if (n == 0)
		ptr[0] = '0';
	else
	ptr = number(ptr, n, len);
	return (ptr);
}
