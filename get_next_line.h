/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:18:24 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/09/29 23:16:52 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* BUFFER_SIZE representa la cantidad de bytes que se leerán o se almacenarán en cada iteración de la función get_next_line().
Determina cuántos caracteres se leerán en cada llamada a la función para construir una línea completa. */
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

/* ACORDARSE DE QUITAR GET_LINE */
char *get_line(char *str);
char	*get_next_line(int fd);

/* FUNCIONES AUXILIARES */

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t bytes);

#endif