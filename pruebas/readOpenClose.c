# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/**
 * Ejemplo de uso de las funciones open, read y close para el manejo de archivos en C
*/

int	main() 
{
    int	fd; //Descriptor del archivo
	char	buf[10]; //Buffer donde se va a guardar lo leido
	ssize_t	n_bytes;

	fd = open("/Users/jvivas-g/Documents/42CursusJD/Cursus/3. Get_next_line/pruebas/prueba3.txt", O_RDONLY);
	if (fd == -1)
		printf("Error al abrir el fichero\n"); //El fichero no existe o no se puede abrir
	n_bytes = read(fd, buf, 5); //De los 10 bytes como maximo leera 5
	close(fd);
	if (n_bytes == 0)
		printf("Archivo vacio\n");
	printf("El numero de caracteres es: %d, y el contenido es: %s\n", (int)n_bytes, buf);
	return (0);
}