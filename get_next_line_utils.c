/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:53:49 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 19:53:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	char			*ss;

	ss = (char *)s;
	uc = (unsigned char)c;
	while (*ss != '\0')
	{
		if (*ss == uc)
			return (ss);
		ss++;
	}
	if (*ss == '\0' && uc != '\0')
		return (NULL);
	return (ss);
}

char	*ft_strdup(const char *s)
{
    char    *p;
    size_t  len;
    int     i;

    i = 0;
    len = ft_strlen((char*)s);
    p = malloc(sizeof(char*) * (len + 1));
    while(s[i] != '\0')
    {
        p[i] = s[i];
        i++;
    }
    p[i] = '\0';
    return (p);
}
char *ft_strjoin(const char *s1, const char *s2)
{
    size_t	l1;
    size_t	l2;
    char	*p;
    int i;
    int	j;

    l1 = ft_strlen(s1);
    l2 = ft_strlen(s2);
    i = 0;
    j = 0;
    p = malloc(sizeof(char*) * (l1 + l2 + 1));
    while (s1[i] != '\0')
        p[j++] = s1[i++];
    i = 0;
    while (s2[i] != '\0')
        p[j++] = s2[i++];
    p[j] = '\0';
    return (p);
}

size_t ft_strlen(const char *s)
{
    size_t i;
    i = 0;
    while(s[i] != '\0')
        i++;
    return (i);
}