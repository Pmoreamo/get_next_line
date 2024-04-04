/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:13:58 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/04 13:44:55 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    ft_strlen(char *buffer)
{
    size_t i;

    i = 0;
    while(buffer[i] != '\0')
    {
        i++;
    }
    return (i);
}

char	*ft_strchr(const char *s, int c)
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
    while (b_llegits > 0 && !ft_strchr(buffer, '\n'))
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

char    *ft_nova_linea(char *buffer)
{
    char    *new_buffer;
    size_t  i;

    i = 0;

    new_buffer = (char *)malloc(sizeof(char)*(i + 1));

    if (!new_buffer)
        return (NULL);

    while(buffer[i] != '\0' && buffer[i] != '\n')
    {
        i++;
        for (size_t j = 0; j < i; j++)
        {
            new_buffer[j] = buffer[j];
            new_buffer[i] = '\0';
        }
    }
    return (new_buffer);
}

