/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:13:58 by pmorello          #+#    #+#             */
/*   Updated: 2024/04/09 11:51:16 by pmorello         ###   ########.fr       */
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

char	*ft_strjoin(char const *buffer, char const *new_buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(*buffer) * (ft_strlen(buffer) + ft_strlen(new_buffer) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i])
	{
		str[j++] = buffer[i];
		i++;
	}
	i = 0;
	while (new_buffer[i])
	{
		str[j++] = new_buffer[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_llegir_linea(char *buffer)
{
	char	*line;
	int		i;
	size_t	length;
	
	line = (char *)malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if(!line)
		return (NULL);

	i = -1;
	while(buffer[++i] != '\n')
	{
		line[i] = buffer[i];
	}
	line[i] = '\0';
	return (line);
}

char	*ft_resta_fd(char *buffer)
{

}