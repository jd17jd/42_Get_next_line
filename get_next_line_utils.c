/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:39:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/09/29 22:53:53 by jvivas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h> /* Para poder usar size_t y NULL */

/**
 * Calculates length of string s
 * @param s string
 * @return number of bytes until character null is found
 */
size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (*s)
	{
		res++;
		s++;
	}
	return (res);
}


/**
 * Allocates memory with malloc() and returns a new string formed by the
 * concatenation of "s1" and "s2".
 * @param s1 The first string.
 * @param s2 The string to added to "s1".
 * @return The new string. NULL if the memory allocation fails
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	while (*s1 != '\0')
		res[i++] = *s1++;
	while (*s2 != '\0')
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}


/**
 * Finds the first occurrence of the character "c" in the first "n" ​​bytes
 * in a memory region "s". 
 * @param s Searched memory region
 * @param c Character to find
 * @param n Examinated bytes in the memory region
 * @return Pointer to byte located. NULL otherwise
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux;
	size_t			i;

	aux = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (aux[i] == (unsigned char) c)
			return ((void *)&aux[i]);
		i++;
	}
	return (0);
}

/**
 * Locates first occurrence of "c" in string "s".
 * Uses the ft_memchr function
 * @param s Searched string.
 * @param c Character to search.
 * @return Pointer to byte located, or NULL if there is no occurrence.
 */
char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}


/**
 * Contiguously allocates enough space for "count" objects that are "size"
 * bytes of memory each and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero. 
 * @param count Number of objects we want to allocate memory for.
 * @param size Bytes of each objects.
 * @return Pointer to alllocated memory. NULL if allocation fails.
*/
void	*ft_calloc(size_t bytes)
{
	size_t	i;
	char	*res;

	i = 0;
	res = malloc(bytes);
	while (i < bytes)
		res[i++] = 0;
	return ((void *) res);
}