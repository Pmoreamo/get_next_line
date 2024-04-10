/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <pmorello@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:13:58 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/10 11:29:00 by pmorello           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
    size_t i;

	if(!str)
		return(free(str), str = NULL, 0);

    i = 0; 
    while(s[i] != '\0') 
    {
        i++;
    }
    return (i);
}

char	*ft_strchr(char *buffer, int c)
{
	int	i;

	i = 0;
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == (char)c)
			return ((char *)&buffer[i]);
		i++;
	}
	if (buffer[i] == (unsigned char) c)
		return ((char *) &buffer[i]);
	return (0);

}

char	*ft_strchr(char *buffer, int c)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == (char)c)
			return ((char *)&buffer[i]);
		i++;
	}
	if (buffer[i] == (unsigned char) c)
		return ((char *) &buffer[i]);
	return (0);
}

char	*ft_strjoin(char const *buffer, char const *new_buffer)
{
	size_t	i;
	size_t	j;
	char suma_buffer;

	if(!buffer) //si falla el buffer
	{
		buffer = malloc(sizeof(char)); //creem un malloc on guardar la info del buffer
		if (!buffer) // comprovem que funcioni, si falla tornar null
			return(free(buffer), buffer = NULL, NULL);
	}
	i = ft_strlen(buffer) + ft_strlen(new_buffer); // a i li donem valor del tamany de la suma de legnth dels 2 buffers
	suma_buffer = (char *)malloc(sizeof(char)*(i + 1)); //creem una reserva de memoria del tamany de char * (lenght dels 2 buffer) + 1
	if (!suma_buffer) //si falla la memo
		return(free(suma_buffer), suma_buffer = NULL, NULL);

	i = -1; //reitera en el buffer i sumar buffer
	j = 0; //reitera en el new_buffer
	while (buffer[++i] != '\0')
		suma_buffer[i] = buffer[i]
	while(new_buffer[j] != '\0')
		suma_buffer[i++] = new_buffer[j++];
	suma_buffer[i] = '\0'; //afegim null al ultim char del suma_buffer
	return(free(buffer),suma_buffer); //tornem la suma dels 2 buffers. 
}

char	*ft_llegir_linea(char *buffer) //quan es trobi linea, copiar linea
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
		line[i] = buffer[i]; //copiem la info del buffer a la linea(malloc)
	if (buffer[i] = '\n') //si es troba salt de linea
		line[i++] = '\n'; //copiar el salt de linea al malloc
	line[i] = '\0'; //afegir el null al malloc
	return (line); //retorn el valor de line, que sera una linea del buffer
}

char	*ft_resta_fd(char *buffer) //si no es troba linea, copiar el contingut restant al buffer
{
	char	*resta;
	size_t	i;
	size_t 	J;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n') //reiterem dins del buffer, fins a trobar el NULL o un salt de linea
		i++;
	if (!buffer[i])
		return (free(buffer), buffer = NULL, NULL);
	resta = (char *)malloc(sizeof(char)*(BUFFER_SIZE + 1)); //creem una reserva de memoria, per posar la resta del buffer
	if(!resta) //si falla resta
		(free(resta), resta = NULL, NULL); //retornar : la lliberacio de memo de resta, asigancio de resta = NULL, NULL
	i++;
	j = 0;
	while (buffer[i] != '\0') //reiterem el buffer fins a trobar NULL
		resta[j++] = buffer[i++]; //copiar el buffer dins del malloc
	resta[i] = '\0'; //assingar el ultim char NULL
	return (free(buffer), resta 0 NULL, resta);
}