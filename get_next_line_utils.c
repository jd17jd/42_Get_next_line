/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvivas-g <jvivas-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:39:56 by jvivas-g          #+#    #+#             */
/*   Updated: 2023/10/09 02:29:01 by jvivas-g         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
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
	int	i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s);
	return (NULL);
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
