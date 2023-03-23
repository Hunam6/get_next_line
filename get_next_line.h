/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunam <hunam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:31 by etattevi          #+#    #+#             */
/*   Updated: 2023/03/23 16:40:11 by hunam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 2048
# endif

typedef unsigned int	t_uint;

//get_next_line.c
int		chr_idx(const char *s, int c);
char	*has_nl(char *saved[OPEN_MAX], int fd);
char	*no_nl(char	*saved[OPEN_MAX], int fd);
char	*ft_strjoin_free(char *s1, char *s2);
char	*get_next_line(int fd);

//get_next_line_utils.c
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, t_uint start, size_t len);

#endif