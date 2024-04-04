/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:54:24 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/04 13:35:14 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *buffer; 
    char        *linea;
    
    if(fd < 0 || BUFFER_SIZE <= 0 )
        return(NULL);
    buffer = ft_llegir_fd( fd, buffer);
    if (!buffer)
        return (NULL);
    linea = ft_llegir_linea(buffer);
    if (!linea)
        return (NULL);
    buffer = ft_nova_linea(buffer);  
    if (!buffer)
        return (NULL);
}