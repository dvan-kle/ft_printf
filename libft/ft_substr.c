/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:15:09 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/27 19:17:52 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	size_t			c;

	if (!str)
		return (NULL);
	if ((size_t)start >= ft_strlen(str))
		return (ft_strdup(""));
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (i >= start && c < len)
			ret[c++] = str[i];
		i++;
	}
	return (ret[c] = '\0', ret);
}
