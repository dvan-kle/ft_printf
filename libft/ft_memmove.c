/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:36:41 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/22 23:53:23 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *sc, size_t len)
{
	size_t				i;
	size_t				j;
	unsigned char		*dest;
	const unsigned char	*src;

	i = 0;
	j = len;
	dest = (unsigned char *) dst;
	src = (const unsigned char *) sc;
	if (!dst && !sc)
		return (0);
	if (dst > sc)
	{
		while (j-- > 0)
			dest[j] = src[j];
	}
	else
	{
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dst);
}
