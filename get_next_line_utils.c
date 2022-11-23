/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:31 by wchan             #+#    #+#             */
/*   Updated: 2022/11/23 12:41:43 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	chr_i(const char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	if (c == '\n')
	{
		while (s[i])
		{
			if (s[i] == c)
				return (i);
			i++;
		}
		return (-1);
	}
	while (s[i] != c)
		i++;
	return (i);
}

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*s = '\0';
		s++;
		i++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	stop;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = chr_i(s, '\0');
	if (len > s_len)
		out = malloc(sizeof(char) * s_len + 1);
	else
		out = malloc(sizeof(char) * len + 1);
	if (!out)
		return (NULL);
	i = 0;
	stop = start + len;
	while (start < stop && s[start] && start < s_len)
		out[i++] = s[start++];
	out[i] = '\0';
	return (out);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (len == 0 || (dst == NULL && src == NULL))
		return (dst);
	if (src < dst)
	{
		i = len;
		while (--i > 0)
			((char *)dst)[i] = ((char *)src)[i];
		((char *)dst)[i] = ((char *)src)[i];
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

char	*eof(char *buff, char *tmp, int *just_read, int tmp_i)
{
	if (!buff[0])
	{
		free(tmp);
		*just_read = 1;
		return (NULL);
	}
	buff[tmp_i] = '\0';
	if (*just_read == 0 && chr_i(buff, '\n') == -1)
	{
		tmp = ft_substr(buff, 0, chr_i(buff, '\0'));
		ft_bzero(buff, chr_i(buff, '\0'));
		*just_read = 1;
		return (tmp);
	}
	if (chr_i(buff, '\n') != -1)
	{
		tmp = ft_substr(buff, 0, chr_i(buff, '\n') + 1);
		tmp_i = chr_i(buff, '\0') - chr_i(buff, '\n') - 1;
		ft_memmove(buff, buff + chr_i(buff, '\n') + 1, tmp_i);
		ft_bzero(buff + tmp_i, chr_i(buff, '\0') - tmp_i);
		*just_read = 1;
		return (tmp);
	}
	*just_read = 0;
	return (NULL);
}
