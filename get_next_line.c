/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:18:06 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/09/30 02:15:49 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* FUNCIONES AUXILIARES */

/**
 * Me devuelve una linea hasta q encuentre el salto de linea
 * RECORDAR PONER STATIC
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



/*
FUNCINES QUE NECESITO:
CONCATENAR STRINGS: Para los casos en los que se me quede algo + lo nuevo
BUSCAR UN CARACTER: Para encontrar el caracter \n y sacar esa linea por pantalla
LONGITUD DE UN STRING: Para restarsela de la longitud total y que se pueda continuar después del \n
*/


/**
 * Returns a full line ending in a ('/n') read by the file descriptor.
 * @param fd file descriptor
*/
char	*get_next_line(int fd)
{
    char    *line;      /* Linea que vamos a devolver */
    static char *stash; /* Variable en la que almacenaremos lo del buffer de read */

    if (fd < 0 || BUFFER_SIZE <= 0) /* Comprobamos fichero abierto correctamente y bs postivo para tener un minimo d lineas a leer */
        return (0);
    /* Estado: Tenemos el "cursor" (read) en el inicio del todo:
        Empezamos a leer caracteres
    */
    return (line);
}