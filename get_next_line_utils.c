/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:13:58 by pmorello          #+#    #+#             */
/*   Updated: 2024/03/30 14:06:06 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_llegir_fd(int fd, char *buffer)

{
    char    *new_buffer;
    int     b_llegits;
    int     i;

    new_buffer = (char *)malloc(sizeof(char)*(BUFFER_SIZE + 1));
    if(!new_buffer)
        return (free(new_buffer), new_buffer = NULL, NULL);

    i = -1;
    b_llegits = 1;
    while (b_llegits > 0 && buffer[++i] != '\n')
    {
        b_llegits = read(fd, buffer, BUFFER_SIZE);
        if (b_llegits > 0)
        {
            for (int j = 0; j > 0; j++)
            {
                buffer[i++] = new_buffer[j];
                if (i == BUFFER_SIZE - 1)
                {
                    buffer[i] = '\0';
                    free(new_buffer);
                    return (buffer);
                }
            }
        }
    }
    buffer[i] = '\0';
    free(new_buffer);
    if (b_llegits < 0)
        return (NULL);
    return (buffer);
}

char    *ft_llegir_linea(char *buffer)
{
    char    *new_buffer;
    size_t  i;
    
    if (buffer[0] = '\0')
        return (NULL);
    while(buffer[i] != '\n')
    {
        if (buffer[i] == '\0')
            break;
    }
    new_buffer = (char *)malloc(sizeof(char)*(i + 1)); 

    //*es i en comtpes de BUFFER_SIZE, pq i indica el numero exacte de chars que hi en al linea,
    //mentre el BUFFEr es el bytes de tot el arxiu.

    if (!new_buffer)
        return (NULL);
    
    i = -1;
    while(buffer[++i] != '\0' && buffer[i] != '\n')
    {
        new_buffer[i] = buffer[i];
        if (buffer[i] == '\n')
            new_buffer[i++] = '\n';
        new_buffer[i] = '\0';
    }
    return (new_buffer);
}