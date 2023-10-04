/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:39:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/10/04 11:56:18 by jvivas-g         ###   ########.fr       */
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
char	*ft_strjoin(const char *s1, const char *s2)
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
 * Locates first occurrence of "c" in string "s".
 * Uses the ft_memchr function
 * @param s Searched string.
 * @param c Character to search.
 * @return Pointer to byte located, or NULL if there is no occurrence.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
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


/**
 * Copies "n" bytes from the memory region pointed to by "src" to the
 * memory region pointed to by "dst".
 * @param dst Memory region to fill
 * @param src Memory region to be copied
 * @param n Number of bytes to copy
 * @return Pointer to the destination memory region "dest".
 * @warning
 * This function does not verify Memory overlapping. It is possible to
 * overwrite a memory region if the destination address and the source address
 * overlap. We must make sure the destination address has enough space to
 * locate the copied data from the source address.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*aux_dest;
	unsigned const char		*aux_src;
	size_t					i;

	if (src == NULL && dst == NULL)
		return (NULL);
	aux_dest = (unsigned char *)dst;
	aux_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		aux_dest[i] = aux_src[i];
		i++;
	}
	return (dst);
}


/**
 * Copies "len" bytes from memory area "src" to memory area "dst".
 * It is capable of handling situations where the source and
 * destination areas overlap.
 * @param dst Memory region where data will be copied
 * @param src Memory region from which data will be copied
 * @param len number of bytes to be copied from "src" to "dst"
 * @return Original value of dst
 * @warning
 * If the destination pointer is greater than the source pointer, the copy is
 * made from the start of the source region to the end of the destination
 * region. Otherwise, the copy is made in the reverse direction, from the end
 * of the source region to the beginning of the destination region
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*aux_dest;
	unsigned const char	*aux_src;

	if (!dst && !src)
		return (NULL);
	aux_dest = (unsigned char *)dst;
	aux_src = (unsigned const char *)src;
	if (aux_dest < aux_src)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len > 0)
		{
			len--;
			aux_dest[len] = aux_src[len];
		}
	}
	return (dst);
}