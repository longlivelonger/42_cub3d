/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _color.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:03:15 by zcris             #+#    #+#             */
/*   Updated: 2022/01/16 15:42:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_color	*color_c(int red, int green, int blue)
{
	t_color	*color;

	color = utls_malloc(sizeof(t_color), 1);
	color->red = red;
	color->green = green;
	color->blue = blue;
	return (color);
}

void	color_d(t_color *color)
{
	utls_free(color);
}

static int	check_color_string(const char *str)
{
	int	i;

	i = 0;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != ',')
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != ',' || !ft_isdigit(str[i - 2]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	return (str[i] == '\0' && ft_isdigit(str[i - 1]));
}

int	str_to_color(t_color *color, const char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strtrim(str, " \n\r\t\v");
	if (!check_color_string(tmp))
	{
		utls_free(tmp);
		return (0);
	}
	color->red = 0;
	color->green = 0;
	color->blue = 0;
	while (ft_isdigit(tmp[++i]) && color->red < 256)
		color->red = color->red * 10 + (tmp[i] - '0');
	while (ft_isdigit(tmp[++i]) && color->green < 256)
		color->green = color->green * 10 + (tmp[i] - '0');
	while (ft_isdigit(tmp[++i]) && color->blue < 256)
		color->blue = color->blue * 10 + (tmp[i] - '0');
	utls_free(tmp);
	if (color->red >= 256 || color->green >= 256 || color->blue >= 256)
		return (0);
	return (1);
}
