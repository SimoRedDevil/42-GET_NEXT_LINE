/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:42:28 by mel-yous          #+#    #+#             */
/*   Updated: 2022/11/22 05:44:15 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (c == '\0' && s)
	{
		while (s[i])
			i++;
	}
	else if (c == '\n' && s)
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	return (i);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptrd;
	char	*ptrs;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptrd = (char *)dst;
	ptrs = (char *)src;
	i = 0;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	slen;
	size_t	i;

	if (!s1)
		return (NULL);
	slen = ft_strlen(s1, '\0');
	i = 0;
	ptr = (char *)malloc(slen + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < slen)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptrj;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1, '\0');
	j = ft_strlen(s2, '\0');
	ptrj = (char *)malloc(i + j + 1);
	if (ptrj == NULL)
		return (NULL);
	ft_memcpy(ptrj, s1, i);
	ft_memcpy(ptrj + i, s2, j + 1);
	return (ptrj);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptrsub;
	size_t	i;
	size_t	slen;

	i = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s, '\0');
	if (*s == '\0')
		return (NULL);
	if (len > slen || (start + len) > slen)
		len = slen - start;
	if (start >= slen)
		return (NULL);
	ptrsub = (char *)malloc(len + 1);
	if (ptrsub == NULL)
		return (NULL);
	while (i < len)
	{
		ptrsub[i] = s[start + i];
		i++;
	}
	ptrsub[i] = '\0';
	return (ptrsub);
}
