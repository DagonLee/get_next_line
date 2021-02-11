/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:37:23 by da-lee            #+#    #+#             */
/*   Updated: 2021/02/11 19:00:39 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char				*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr != c)
	{
		if (!*ptr)
		{
			return (0);
		}
		ptr++;
	}
	return (ptr);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			max_len;
	size_t			i;
	size_t			j;

	if (!s)
		return (0);
	max_len = ft_strlen(s);
	if (start >= max_len)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	i = start;
	j = 0;
	while (j < len && s[i])
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = 0;
	return (str);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s2 || !s1)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}
