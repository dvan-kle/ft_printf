/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kle <dvan-kle@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 15:50:45 by dvan-kle      #+#    #+#                 */
/*   Updated: 2022/10/28 15:38:52 by dvan-kle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_address(void *p);
int	ft_int(int nb);
int	ft_uns_int(int nb);
int	ft_hexa_low(unsigned int nb);
int	ft_hexa_up(unsigned int nb);
int	ft_printf(const char *str, ...);

#endif