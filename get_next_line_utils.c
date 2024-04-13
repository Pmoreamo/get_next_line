/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:13:58 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/13 14:18:42 by pmorello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (free(str), str = NULL, 0);
	i = 0;
	while (str[i] != '\0')
		i++;
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

char	*ft_strjoin(char *buffer, char *new_buffer)
{
	size_t	i;
	size_t	j;
	char	*suma_buffer;

	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		if (!buffer)
			return (free(buffer), buffer = NULL, NULL);
		buffer[0] = '\0';
	}
	if (!new_buffer)
		return (free(new_buffer), new_buffer = NULL, NULL);
	i = ft_strlen(buffer) + ft_strlen(new_buffer);
	suma_buffer = malloc(sizeof(char) * (i + 1));
	if (!suma_buffer)
		return (free(suma_buffer), suma_buffer = NULL, NULL);
	i = -1;
	j = 0;
	while (buffer[++i] != '\0')
		suma_buffer[i] = buffer[i];
	while (new_buffer[j] != '\0')
		suma_buffer[i++] = new_buffer[j++];
	return (suma_buffer[i] = '\0', free(buffer), suma_buffer);
}

char	*ft_llegir_linea(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i++] == '\n')
			break ;
	}
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
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
		return (free(buffer), buffer = NULL, NULL);
	resta = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (!resta)
		return (free(buffer), buffer = NULL, NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		resta[j++] = buffer[i++];
	resta[j] = '\0';
	return (free(buffer), resta = NULL, resta);
}
