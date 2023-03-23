/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:31 by etattevi          #+#    #+#             */
/*   Updated: 2023/03/23 16:41:29 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*out;
	size_t	i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	out = malloc(count * size);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
		((char *)out)[i++] = '\0';
	return (out);
}

char	*ft_strdup(const char *s1)
{
	int		idx;
	char	*dest;

	idx = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, t_uint start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	stop;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		out = ft_calloc(sizeof(char), s_len + 1);
	else
		out = ft_calloc(sizeof(char), len + 1);
	if (!out)
		return (NULL);
	i = 0;
	stop = start + len;
	while (start < stop && s[start] && start < s_len)
		out[i++] = s[start++];
	return (out);
}
