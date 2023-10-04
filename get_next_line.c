/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:18:06 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/10/04 13:13:55 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @param str String de caracteres 
 * @return Me devuelve una linea hasta q encuentre el salto de linea
*/
char	*ft_get_line(char *str)
{
	char	*result;
    int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	result = (char *)calloc((i + 2), sizeof(char)); /* Reservamos memoria para la palabra hasta antes del \n */
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n') /* Copiamos la pabra en el resultado */
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == '\n') /* Porque me dice que debo poner el salto de linea incluido */
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0'; /* Siempre ponemos el ultimo bytes de la palabra el delimitador NULL */
	return (result);
}


/**
 * @param fd Descriptor desde donde leer para almacenar en nuestra variable auxiliar
 * @param stash Variable estatica para concatenar con o ue hagamos
 * @return String con las cadenas concatenadas
*/
char	*ft_append(int fd, char *stash)
{
	char aux[BUFFER_SIZE + 1]; /* Variable para almacenar la lectura */
	int read_bytes; /* Me devuelve el resultado de cuántos bytes ha leído */

	read_bytes = 1;
	while (!ft_strchr(aux, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, aux, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		aux[read_bytes] = '\0';
		stash = ft_strjoin(stash, aux);
	}
	return (stash);
}

/**
 * @param stash Variable estatica que contiene nuestra linea a devolver
 * @return String conteniendo nuestra linea
*/
char *ft_short(char *stash) {
	char *result;

	result = ft_get_line(stash); /* Me duvuelve la linea hasya el \n */
	stash = ft_memmove(stash, stash + ft_strlen(result), ft_strlen(stash) - ft_strlen(result) + 1);
	/* Modifico stash y hago que empiece para después del \n */
	
	return (result);
}


/**
 * Returns a full line ending in a ('/n') read by the file descriptor.
 * @param fd file descriptor
*/
char	*get_next_line(int fd)
{
    char    *line;      /* Linea que vamos a devolver */
    static char *stash; /* Variable en la que almacenaremos lo del buffer de read */

    if (fd < 0 || BUFFER_SIZE < 0) /* Comprobamos fichero abierto correctamente y bs postivo para tener un minimo d lineas a leer */
        return (0);
	stash = ft_append(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = ft_short(stash);
    return (line);
}