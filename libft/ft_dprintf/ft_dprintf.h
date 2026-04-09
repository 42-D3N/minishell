/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:42 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 19:37:12 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdarg.h>

int	ft_dprintf_putchar(char c, int fd);
int	ft_dprintf_putstr(char *s, int fd);
int	ft_dprintf_putpointer(unsigned long p, int fd);
int	ft_dprintf_putnbr(int nb, int fd);
int	ft_dprintf_putuint(unsigned int nb, int fd);
int	ft_dprintf_puthex(unsigned int nb, int cptl, int fd);
int	ft_dhandle(char conv, va_list args, int fd);
int	ft_dprintf(int fd, const char *s, ...);

#endif