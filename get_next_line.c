/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:54:24 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/06 13:52:42 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1024

char    ft_llegir_fd(int fd, char *buffer)
{
        char    *new_buffer;
        int     b_llegits;

        new_buffer = (char *)malloc(sizeof(char)*(BUFFER_SIZE + 1)); //creem un malloc on guardar les dades llegides 
        if (!new_buffer)
            return (NULL);
        
        b_llegits = 1; //es guarda el numero de bytes llegits en cada iteracio.. 
        while (b_llegits > 0 && !ft_strchr(buffer, '\n')) //entra en bucle fins que trobi un salt de linea o b_llegits sigui menor a 0. 
        {
            b_llegits = read(fd, buffer, BUFFER_SIZE); //llegira del fd X bytes i els guardara en el buffer, retornara el num de bytes llegits
            if (b_llegits > 0); //mentres hi haguin bytes llegits
            {
                new_buffer[b_llegits] = '\0'; //apliquem que ell ultim char del buffer sigui NULL
                buffer = ft_strjoin(buffer, new_buffer); //ajuntem les dades del buffer(argument), a la nova cadena new_buffer. 
                //Els guardem en el buffer(a tornar), cada cop que es faci la funcion read les dades buffer(agument) s'afegeixen al buffer(a tornar) utilitzan strjoin.  
            }
        } 
        free(buffer);
        return (buffer);  
}

char	*get_next_line(int fd)
{
    static char *buffer;
    char        *line;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
    buffer = ft_llegir_fd; //llegeix dades del buffer fins que trobi un salt de linea o acabi. 
    if(!buffer)
        return (NULL);
    //line = ft_llegir_linea(buffer) //extrau una linea del buffer i retorna la linea
    //  if(!linea)
    //      return(NULL)
    //bufffer = ft_resta_fd //actualitza el buffer, un cop extret la linea, retorna la resta de la cadena
    //  if(!buffer)
    //      return(NULL);
    // return (line); /retorn la linea extreta del buffer 



    //ft_llegir_fd, llegir dades del buffer
    //ft_llegir_linea, extrau una linea del buffer i retorna la linea
    //ft_resta_fd, un cop extrau la linea segueix llegint del fd fins al final. 
}