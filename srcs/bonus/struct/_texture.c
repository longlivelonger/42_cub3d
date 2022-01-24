/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _texture.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:40:20 by zcris             #+#    #+#             */
/*   Updated: 2022/01/17 16:31:12 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_texture	*texture_c(void)
{
	t_texture	*texture;

	texture = utls_malloc(sizeof(t_texture), 1);
	texture->file_path = NULL;
	texture->bgcolor = color_c(0, 255, 0);
	texture->mlx_img = mlx_img_c();
	texture->mlx_img->width = SOLID_COLOR_TEXTURE_WIDTH;
	texture->mlx_img->height = SOLID_COLOR_TEXTURE_HEIGHT;
	return (texture);
}

void	texture_d(t_texture *t)
{
	mlx_img_d(t->mlx_img);
	color_d(t->bgcolor);
	utls_free(t->file_path);
	utls_free(t);
}

int	texture_set_file(t_texture *t, const char *file_path)
{
	int	fd;

	utls_free(t->file_path);
	t->file_path = ft_strtrim(file_path, " \n\r\t\v");
	fd = open(t->file_path, O_RDONLY);
	if (fd < 0)
	{
		errors_print(ERRORS_PREFIX);
		perror(t->file_path);
		exit(1);
	}
	close(fd);
	return (1);
}

void	texture_set_array_of_files(t_door *d, const char *file_path, int count)
{
	int		i;
	char	*tmp_path;
	char	*tmp_number;
	char	*tmp_finish;
	char	*tmp_start;

	i = -1;
	while (++i < count)
	{
		tmp_start = ft_strtrim(file_path, " \n\r\t\v");
		tmp_number = ft_itoa(i);
		tmp_finish = ft_strjoin(tmp_number, ".xpm");
		tmp_path = ft_strjoin(tmp_start, tmp_finish);
		texture_set_file(d->frames[i], tmp_path);
		utls_free(tmp_number);
		utls_free(tmp_finish);
		utls_free(tmp_path);
		utls_free(tmp_start);
	}
}
