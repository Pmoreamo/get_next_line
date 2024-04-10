/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:45:43 by lprieto-          #+#    #+#             */
/*   Updated: 2024/03/28 09:39:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//LLIBRERIAS
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

//FUNCIONS
char	*get_next_line(int fd);
char	*ft_read_fd(int fd, char *buffer);
char	*ft_read_line(char *buffer);
char	*ft_new_line(char *buffer);
size_t  ft_strlen(char *str);
char	*ft_strchr(char *buffer, int c);
char	*ft_strjoin(char *buffer, char *new_buffer);

#endif