/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:55:47 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/09 13:43:38 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFFER_SIZE 42

//llibrerias

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//funcions
size_t  ft_strlen(const char *s);
char    *get_next_line(int fd);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char *buffer, char *new_buffer);
char    *ft_llegir_linea(char *buffer);
char    *ft_resta_fd(char *buffer);


#endif