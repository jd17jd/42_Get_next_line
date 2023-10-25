/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:18:06 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/10/25 18:12:27 by jvivas-g         ###   ########.fr       */
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
	result = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	result = (char *)ft_calloc((i + 2), sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}

/**
 * @param fd Descriptor desde donde leer
 * @param stash Variable estatica para concatenar con o ue hagamos
 * @return String con las cadenas concatenadas
*/
char	*ft_append(int fd, char *stash)
{
	char	aux[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	if (!stash)
		stash = ft_strjoin("", "");
	while (!ft_strchr(aux, '\n') && read_bytes)
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
 * @param stash Variable estatica que modificaremos moviendo su puntero
 * @return String con el nuevo vector despues del /n
*/
char	*ft_new_start(char *stash)
{
	char	*result;
	int		i;
	int		j;

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
	result = (char *)calloc(1 + ft_strlen(stash) - i, sizeof(char)); //OJO
	if (!result)
		return (NULL);
	j = 0;
	while (stash[i + j])
	{
		result[j] = stash[i + j];
		j++;
	}
	return (result);
}

/**
 * Returns a full line ending in a ('/n') read by the file descriptor.
 * @param fd file descriptor
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_append(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_new_start(stash);
	return (line);
}
