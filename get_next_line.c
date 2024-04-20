/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 10:54:24 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/18 12:17:04 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *buffer)
{
	char	*new_buffer;
	int		b_llegits;

	new_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	b_llegits = 1;
	if (!new_buffer)
		return (free(buffer), buffer = NULL, NULL);
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
	if (b_llegits < 0)
		return (free(buffer), buffer = NULL, NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = ft_read_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_new_line(buffer);
	return (line);
}

/* ft_read_fd, llegir dades del buffer
 ft_read_line, extrau una linea del buffer i la retorna
 ft_new_line, un cop extrau la linea segueix a la seguent linea

   int main()
    fd = open("archivo.txt", O_RDONLY);
    if (fd == -1) 
    {
        perror("Error al abrir el archivo");
        return 1;
    }
    char *line;
    while ((line = get_next_line(fd)) != NULL) 
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}*/
