/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:43:47 by julauren          #+#    #+#             */
/*   Updated: 2026/02/06 14:59:15 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_free(char *buffer, char **readed_file)
{
	if (buffer)
		free(buffer);
	if (*readed_file)
	{
		free(readed_file);
		readed_file = NULL;
	}
}

static void	ft_fill_file(char *buffer, char **readed_file, int fd)
{
	char	*tmp;
	ssize_t	size;

	size = 1;
	while (size)
	{
		size = read(fd, buffer, 50);
		if (size == -1 || (size == 0 && *readed_file == NULL))
		{
			ft_free(buffer, readed_file);
			return ;
		}
		if (size == 0)
			break ;
		buffer[size] = '\0';
		tmp = ft_strjoin(*readed_file, buffer);
		if (!tmp)
		{
			ft_free(buffer, readed_file);
			return ;
		}
		free(*readed_file);
		*readed_file = tmp;
	}
	free(buffer);
}

char	*ft_read_file(char *str)
{
	int		fd;
	char	*readed_file;
	char	*buffer;

	readed_file = NULL;
	buffer = malloc(sizeof(*buffer) * 51);
	if (!buffer)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (NULL);
	}
	ft_fill_file(buffer, &readed_file, fd);
	close(fd);
	return (readed_file);
}
