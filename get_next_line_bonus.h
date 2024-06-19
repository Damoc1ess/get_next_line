/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:38:09 by fflamion          #+#    #+#             */
/*   Updated: 2024/06/11 15:26:55 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

size_t	ft_strlen(char *s);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strdup(char *s1);

char	*ft_strchr(char *s, int c);

char	*ft_substr(char *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

char	*ft_free(char **str);

#endif