/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:55:47 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/02 14:25:14 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE.H
#define GET_NEXT_LINE.H
#define BUFFER_SIZE 42

//llibrerias

#include <unistd.h>
#include <stdlib.h>

//funcions
char    *get_next_line(int fd);
char    *ft_llegir_fd(int fd, char *buffer);
char    *ft_llegir_linea(char *buffer);
char    *ft_nova_linea(char *buffer);

#endif