/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:22:15 by zcris             #+#    #+#             */
/*   Updated: 2022/01/13 19:43:41 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERRORS_SHELL_PARAMS	"usage: ./cub3D your_map_file.cub"
# define ERRORS_FILE_IS_NOT_CUB	"~!: cub3D: cub3D supports only .cub map files"
# define ERRORS_FILE_NOT_FOUND	"~!: cub3D: can't find map file "
# define ERRORS_PREFIX			"~!: cub3D: "
# define ERRORS_NO_PLAYER		"~!: cub3D: no player on map"
# define ERRORS_MISSED_INFO		"~!: cub3D: missed information"
# define ERRORS_BAD_MAP			"~!: cub3D: bad map content"
# define ERRORS_NOT_SURROUNDED	"~!: cub3D: map not surrounded by walls"
# define ERRORS_EMPTY_MAP		"~!: cub3D: empty map"
# define ERRORS_MALLOC			"~!: cub3D: malloc error"

#endif