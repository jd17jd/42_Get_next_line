/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:18:06 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/10/09 02:51:18 by jvivas-g         ###   ########.fr       */
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
	//char aux[BUFFER_SIZE + 1]; /* Variable para almacenar la lectura */
	char *aux;
	int read_bytes; /* Me devuelve el resultado de cuántos bytes ha leído */
	
	read_bytes = 1;
	aux = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!aux)
		return (NULL);
	while (!ft_strchr(aux, '\n') && read_bytes)
	{
		read_bytes = read(fd, aux, BUFFER_SIZE);
		if (read_bytes == -1) {
			free(aux);
			return (NULL);
		}
		aux[read_bytes] = '\0';
		stash = ft_strjoin(stash, aux);
	}
	free (aux);
	return (stash);
}


char	*ft_move_start(char *stash) {
	int	i;
	int j;
	char	*result;
	
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	if (stash[i] == '\n')
		i++;
	result = (char *)calloc(1 + ft_strlen(stash) - i, sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	while (stash[i + j])
	{
		result[j] = stash[i + j];
		j++;
	}
	result[j] = '\0';
	free(stash);
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
	
    if (fd < 0 || BUFFER_SIZE <= 0) /* Comprobamos fichero abierto correctamente y bs postivo para tener un minimo d lineas a leer */
        return (NULL);
	stash = "";
	stash = ft_append(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash); /* Me duvuelve la linea hasya el \n */
	//stash = ft_memmove(stash, stash + (shortLength - 2), (longLength - 1 - shortLength - 1));
	stash = ft_move_start(stash);
    return (line);
}