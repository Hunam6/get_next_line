/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:31 by wchan             #+#    #+#             */
/*   Updated: 2022/11/23 12:42:47 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff;
	int			nb_of_read;
	int			just_read;
	int			tmp_i;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (NULL);
	nb_of_read = 0;
	while (42)
	{
		tmp = malloc(chr_i(buff, '\0') + ++nb_of_read * BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		ft_memmove(tmp, buff, chr_i(buff, '\0') + 1);
		if (buff != tmp)
			free(buff);
		buff = tmp;
		tmp_i = chr_i(buff, '\0');
		just_read = read(fd, buff + tmp_i, BUFFER_SIZE);
		tmp_i += just_read;
		tmp = eof(buff, tmp, &just_read, tmp_i);
		if (just_read)
			return (tmp);
	}
}
