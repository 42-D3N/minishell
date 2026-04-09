/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:42 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/12 00:26:32 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf_putchar(char c);
int	ft_printf_putstr(char *s);
int	ft_printf_putpointer(unsigned long p);
int	ft_printf_putnbr(int nb);
int	ft_printf_putuint(unsigned int nb);
int	ft_printf_puthex(unsigned int nb, int cptl);
int	ft_handle(char conv, va_list args);
int	ft_printf(const char *s, ...);

#endif