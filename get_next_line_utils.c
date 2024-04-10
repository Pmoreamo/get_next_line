/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:13:58 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/10 10:35:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((char)s[i] != '\0')
	{
		if ((char)s[i] == (char) c)
		{
			return (&((char *)s)[i]);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return (&((char *)s)[i]);
	}
	return (0);
}

char	ft_strjoin(char const *buffer, char const *new_buffer)
{
	size_t	i;
	size_t	j;
	char suma_buffer;

	if(!buffer) //si falla el buffer
	{
		buffer = malloc(sizeof(char)); //creem un malloc on guardar la info del buffer
		if (!buffer) // comprovem que funcioni, si falla tornar null
			free(buffer); //alliberem la memoria
			buffer = NULL; //assignem NULL
			return (NULL); //tornem NULL
	}
	i = ft_strlen(buffer) + ft_strlen(new_buffer); // a i li donem valor del tamany de la suma de legnth dels 2 buffers
	suma_buffer = (char *)malloc(sizeof(char)*(i + 1)); //creem una reserva de memoria del tamany de char * (lenght dels 2 buffer) + 1
	if (!suma_buffer) //si falla la memo
	{
		free(suma_buffer) //alliberar la memo
		suma_buffer = NULL; // assignar null
		return (NULL); //retornar null
	}

	i = -1; //reitera en el buffer i sumar buffer
	j = 0; //reitera en el new_buffer
	while (buffer[++i] != '\0')
		suma_buffer[i] = buffer[i]
	while(new_buffer[j] != '\0')
		suma_buffer[i++] = new_buffer[j++];
	suma_buffer[i] = '\0'; //afegim null al ultim char del suma_buffer
	free(buffer);
	return(suma_buffer); //tornem la suma dels 2 buffers. 
}

char	ft_llegir_linea(char *buffer) //quan es trobi linea, copiar linea
{
	char	*line;
	size_t	i;
	
	i = 0;
	while(buffer[i++] != '\0') // reiterem en el buffer fins al null
	{
		if (buffer[i] == '\n') //si troba salt de linea
			break; //para el loop
	}
	line = (char *)malloc(sizeof(char)*(BUFFER_SIZE + 1)); //crear una reserva de memoria tipus char, tamany de char * buffer_size + 1
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] != '\0' && buffer[i] != '\n') // mentres el buffer no sigui igual al null o salt de linea
	{
		line[i] = buffer[i]; //copiem la info del buffer a la linea(malloc)
	}
	if (buffer[i] = '\n') //si es troba salt de linea
		line[i++] = '\n'; //copiar el salt de linea al malloc
	line[i] = '\0'; //afegir el null al malloc
	return (line); //retorn el valor de line, que sera una linea del buffer
}

char	ft_resta_fd(char *buffer) //si no es troba linea, copiar el contingut restant al buffer
{
	char	*resta;
	size_t	i;


}