/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:55:47 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/13 14:19:32 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

//llibrerias
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

//funcions
char	*ft_strchr(char *buffer, int c);
char	*ft_strjoin(char *buffer, char *new_buffer);
char	*get_next_line(int fd);
char    *ft_llegir_fd(int fd, char *buffer);
char	*ft_llegir_linea(char *buffer);
char	*ft_resta_fd(char *buffer);
 
#endif
