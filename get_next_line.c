/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:33:45 by jeekim            #+#    #+#             */
/*   Updated: 2022/06/14 17:33:47 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*for_next(char *save)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen((const char *)save) - i));
	if (!str)
		return (NULL);
	j = 0;
	while (save[i + 1])
	{
		str[j] = save[i + 1];
		j++;
		i++;
	}
	str[j] = 0;
	free (save);
	return (str);
}

char	*rtg(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*read_and_save(int fd, char *save)
{
	char	*buf;
	int		rd;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	while (!ft_strchr((const char *)save, '\n') && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[rd] = 0;
		save = ft_strjoin((const char *)save, buf);
	}
	free (buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = rtg(save);
	save = for_next(save);
	return (line);
}
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("a.c", O_RDONLY);
	char *str = get_next_line(fd);
}