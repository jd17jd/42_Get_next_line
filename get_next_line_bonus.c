/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:06:55 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/10/30 19:20:54 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @param str String de caracteres 
 * @return Me devuelve una linea hasta q encuentre el salto de linea
*/
char	*ft_get_line(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = (char *)ft_calloc((i + 1), sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = str[i];
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
	char	*aux2;

	read_bytes = 1;
	ft_bzero(aux, BUFFER_SIZE + 1);
	if (!stash)
		stash = ft_strjoin("", "");
	while (!ft_strchr(aux, '\n') && read_bytes)
	{
		read_bytes = read(fd, aux, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			ft_bzero(stash, 1);
			break ;
		}
		aux[read_bytes] = '\0';
		aux2 = stash;
		stash = ft_strjoin(stash, aux);
		free(aux2);
	}
	return (stash);
}

/**
 * Aux para lineas de ft_new_start
*/
void	aux_strcat(int i, int j, char *stash, char *result)
{
	while (stash[i + j])
	{
		result[j] = stash[i + j];
		j++;
	}
}

/**
 * @param stash Variable estatica que modificaremos moviendo su puntero
 * @return String con el nuevo vector despues del /n
*/
char	*ft_new_start(char *stash)
{
	char	*result;
	char	*aux;
	int		i;
	int		j;

	i = 0;
	aux = stash;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	if (stash[i] == '\n')
		i++;
	result = (char *)ft_calloc(1 + ft_strlen(stash) - i, sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	aux_strcat(i, j, stash, result);
	free(aux);
	return (result);
}

/**
 * Returns a full line ending in a ('/n') read by the file descriptor.
 * @param fd file descriptor
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_append(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_new_start(stash[fd]);
	return (line);
}
