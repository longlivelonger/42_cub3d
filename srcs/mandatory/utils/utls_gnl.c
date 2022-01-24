/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 07:47:04 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	*gnl_util_free(char **s0, char **s1)
{
	if (NULL != s0)
	{
		if (NULL != *s0)
		{
			free(*s0);
			*s0 = NULL;
		}
	}
	if (NULL != s1)
	{
		if (!(NULL == *s1))
		{
			free(*s1);
			*s1 = NULL;
		}
	}
	return (NULL);
}

static char	gnl_util_read_from_buffer(char **buffer, int *last_index)
{
	char	result;
	int		i;

	result = **buffer;
	if (*last_index == 0)
		return (result);
	i = 0;
	while (i < *last_index)
	{
		*(*buffer + i) = *(*buffer + i + 1);
		i++;
	}
	*(*buffer + *last_index) = '\0';
	*last_index = *last_index - 1;
	return (result);
}

static int	gnl_util_srting_add_char(char **dst, size_t *str_size, char c)
{
	char	*temp_string;
	size_t	i;

	temp_string = NULL;
	temp_string = utls_malloc(sizeof(char *), *str_size + 2);
	if (NULL == temp_string)
		return (-1);
	i = 0;
	while (i < *str_size)
	{
		*(temp_string + i) = *(*dst + i);
		i++;
	}
	*(temp_string + i) = c;
	*(temp_string + i + 1) = '\0';
	gnl_util_free(dst, NULL);
	*dst = temp_string;
	*str_size = *str_size + 1;
	return (0);
}

static	char	*f(int fd, char **buffer, int *buffer_index, int buffer_size)
{
	char			*result;
	size_t			result_size;
	unsigned int	c;

	result_size = 0;
	result = NULL;
	while (1)
	{
		if (*buffer_index == 0)
		{
			*buffer_index = read(fd, *buffer, buffer_size);
			if (!(*buffer_index >= 0))
				return (gnl_util_free(buffer, NULL));
			if (*buffer_index == 0)
			{
				gnl_util_free(buffer, NULL);
				return (result);
			}
		}
		c = gnl_util_read_from_buffer(buffer, buffer_index);
		if (gnl_util_srting_add_char(&result, &result_size, c) < 0)
			return (gnl_util_free(buffer, &result));
		if (c == '\n')
			return (result);
	}
}

char	*utls_gnl(int fd)
{
	static char	*buffer;
	static int	buffer_index;
	static int	_fd;

	if ((read(fd, NULL, 0) < 0))
		return (NULL);
	if (_fd != fd)
	{
		gnl_util_free(&buffer, NULL);
		_fd = fd;
	}
	if (NULL == buffer)
		buffer = utls_malloc(sizeof(char *), BUFFER_SIZE_GNL);
	if (NULL == buffer)
		return (buffer);
	return (f(fd, &buffer, &buffer_index, BUFFER_SIZE_GNL));
}
