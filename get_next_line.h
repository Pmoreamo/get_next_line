/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:55:47 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/10 11:48:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFFER_SIZE 42

//llibrerias

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

//funcions
size_t  ft_strlen(char *str);
char    *ft_strchr(char *buffer, int c);
char    *ft_strjoin(char *buffer, char *new_buffer);
char    *get_next_line(int fd),
char    *ft_llegir_linea(char *buffer);
char    *ft_resta_fd(char *buffer);


#endif