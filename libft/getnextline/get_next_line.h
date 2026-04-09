/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:50:02 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/30 13:41:37 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void	gnl_bzero(void *s, size_t n);
size_t	gnl_strlcpy(char *dest, const char *src, size_t size);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(const char *str);
char	*get_next_line(int fd);

#endif