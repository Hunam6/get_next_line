/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchan <wchan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:32:31 by wchan             #+#    #+#             */
/*   Updated: 2022/11/23 12:48:05 by wchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

char	*get_next_line(int fd);
int		chr_i(const char *s, char c);
void	ft_bzero(char *s, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t og_len);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*eof(char *buff, char *tmp, int *just_read, int tmp_i);

#endif