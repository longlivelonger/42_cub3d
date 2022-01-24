/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:27:26 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:01:45 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

typedef struct s_strim {
	size_t	string_start;
	size_t	string_end;
	size_t	i;
}t_strim;

static size_t	ft_strtrim_strlen(const char *s);
static int		ft_strtrim_iscontains(const char *s, char const c);
static char		*ft_strtrim_zerostr(void);

char	*ft_strtrim(char const *s1, char const *set)
{
	t_strim	s;
	char	*result;

	if (NULL == s1 || NULL == set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strtrim_zerostr());
	s.string_start = 0;
	while (ft_strtrim_iscontains(set, *(s1 + s.string_start++)))
		if (*(s1 + s.string_start) == '\0')
			return (ft_strtrim_zerostr());
	s.string_end = ft_strtrim_strlen(s1) - 1;
	while (ft_strtrim_iscontains(set, *(s1 + s.string_end--)))
		;
	result = NULL;
	result = malloc(sizeof(char) * (2 + ++s.string_end - --s.string_start));
	if (NULL == result)
		return (result);
	s.i = 0;
	while (s.string_start + s.i <= s.string_end)
		*(result++) = *(s1 + s.string_start + s.i++);
	*(result) = '\0';
	return (result - s.i);
}

static size_t	ft_strtrim_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

static int	ft_strtrim_iscontains(const char *s, char const c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		if (*(s + i++) == c)
			return ((int)c);
	return (0);
}

static char	*ft_strtrim_zerostr(void)
{
	char	*result;

	result = NULL;
	result = malloc (sizeof(char));
	if (NULL == result)
		return (result);
	*result = '\0';
	return (result);
}
