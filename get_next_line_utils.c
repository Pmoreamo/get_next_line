/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:13:58 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/11 12:08:13 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (free (str), str = NULL, 0);
	i = 0;
	while (str[i] != '\0')
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
		return (free (buffer), buffer = NULL, NULL);
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

char	*ft_strjoin(char *buffer, char *new_buffer)
{
	size_t	i;
	size_t	j;
	char	*suma_buffer;

	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		if (!buffer)
			return (free (buffer), buffer = NULL, NULL);
	}
	i = ft_strlen(buffer) + ft_strlen(new_buffer);
	suma_buffer = (char *)malloc(sizeof(char) * (i + 1));
	if (!suma_buffer)
		return (free (suma_buffer), suma_buffer = NULL, NULL);
	i = -1;
	j = 0;
	while (buffer[++i] != '\0')
		suma_buffer[i] = buffer[i];
	while (new_buffer[j] != '\0')
		suma_buffer[i++] = new_buffer[j++];
	suma_buffer[i] = '\0';
	return (free (buffer), suma_buffer);
}

char	*ft_llegir_linea(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	while (buffer[i++] != '\0')
	{
		if (buffer[i] == '\n')
			break ;
	}
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (free (line), line = NULL, NULL);
	i = -1;
	while (buffer[++i] != '\0' && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_resta_fd(char *buffer)
{
	char	*resta;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free (buffer), buffer = NULL, NULL);
	resta = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!resta)
		return (free (resta), resta = NULL, NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		resta[j++] = buffer[i++];
	resta[i] = '\0';
	return (free (buffer), resta = NULL, resta);
}
