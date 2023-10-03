/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:44:04 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/10/04 00:26:21 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <fcntl.h>

int main() {
    char	*line; /* Buffer en el que guardamnos la linea resultado de nuestra funcion final */
    int		i; /* Contador por el que iteraremos nuestro fichero */
    int		fd1; 
    int		fd2;
    int		fd3;
	
	fd1 = open("/Users/jvivas-g/Documents/2. Get next line/pruebas/prueba1.txt", O_RDONLY);
	if (fd1 == -1) printf("Error al abrir el fichero 'pruebas1.txt'\n"); /* El fichero no existe o no se puede abrir */
	else { printf("fichero 'pruebas1.txt' abierto satisfactoriamente\n"); }

	fd2 = open("/Users/jvivas-g/Documents/2. Get next line/pruebas/prueba2.txt", O_RDONLY);
	if (fd2 == -1) printf("Error al abrir el fichero 'pruebas2.txt'\n");
	else { printf("fichero 'pruebas2.txt' abierto satisfactoriamente\n"); }

	fd3 = open("/Users/jvivas-g/Documents/2. Get next line/pruebas/prueba3.txt", O_RDONLY);
	if (fd3 == -1) printf("Error al abrir el fichero 'pruebas3.txt'\n");
	else { printf("fichero 'pruebas3.txt' abierto satisfactoriamente\n"); }


/* 	i = 0;
	while (i < 3) {
		line = get_next_line(fd1);
		printf("line: %d: %s\n", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line: %d: %s\n", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line: %d: %s\n", i, line);
		free(line);
		
		i++;
	} */
	
	char	buf[100]; //Buffer donde se va a guardar lo leido
	char	*result;
	ssize_t	n_bytes;
	
	n_bytes = read(fd2, buf, 100);
	printf("El numero de caracteres es: %d, y el contenido es: %s\n", (int)n_bytes, buf);

	result = ft_get_line(buf);
	printf("%s\n", result);

	close(fd1);
		printf("fichero 'pruebas1.txt' cerrado\n");
	close(fd2);
		printf("fichero 'pruebas1.txt' cerrado\n");
	close(fd3);
		printf("fichero 'pruebas1.txt' cerrado\n");

    return (0);
}