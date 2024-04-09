/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:54:24 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/09 13:46:38 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    ft_llegir_fd(int fd, char *buffer)
{
    char    *new_buffer;
    int     b_llegits;

    new_buffer = (char *)malloc(sizeof(char)*(BUFFER_SIZE + 1));
    if (!new_buffer)
        return (NULL);
        
    b_llegits = 1; 
    while (b_llegits > 0 && !ft_strchr(buffer, '\n')) 
    {
        b_llegits = read(fd, new_buffer, BUFFER_SIZE);
        if (b_llegits > 0)
        {
            new_buffer[b_llegits] = '\0'; 
            buffer = ft_strjoin(buffer, new_buffer);
        }
    } 
    free(new_buffer); 
    return (buffer);
}

char	*get_next_line(int fd)
{
    static char *buffer;
    char        *line;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
    buffer = ft_llegir_fd(fd, buffer);
    if(!buffer)
        return (NULL);
    line = ft_llegir_linea(buffer);
    if(line)
        return(NULL);
    buffer = ft_resta_fd(buffer);
    if(!buffer)
        return(NULL);
    return (line); 
    
    //ft_llegir_fd, llegir dades del buffer
    //ft_llegir_linea, extrau una linea del buffer i retorna la linea
    //ft_resta_fd, un cop extrau la linea segueix llegint del fd fins al final. 
}