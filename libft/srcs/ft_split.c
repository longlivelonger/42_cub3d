/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcris <zcris@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 07:13:07 by zcris             #+#    #+#             */
/*   Updated: 2021/11/04 16:00:56 by zcris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

typedef struct t_split_vars
{
	char	**result;
	char	*tmp;
	size_t	stop;
	int		i;
}t_split_vars;

static int	ft_split_init(t_split_vars *v);
static char	*get_chank(char const *s, size_t start, size_t stop);
static int	append(char ***arr, char **str, int i);
static void	array_free(char ***arr);

char	**ft_split(char const *s, char c)
{
	t_split_vars	v;

	if (NULL == s || ft_split_init(&v) < 0)
		return (NULL);
	while (*s == c && *s)
		s++;
	while (*s)
	{
		v.stop = 0;
		while (*s != c && *s)
		{
			v.stop++;
			s++;
		}
		v.tmp = get_chank(s - v.stop, 0, v.stop);
		if (NULL == v.tmp)
		{
			array_free(&v.result);
			return (NULL);
		}
		append(&v.result, &v.tmp, ++v.i);
		while (*s == c && *s)
			s++;
	}
	return (v.result);
}

static int	ft_split_init(t_split_vars *v)
{
	v->stop = 0;
	v->i = -1;
	v->result = (char **)malloc(sizeof(*v->result));
	if (v->result == NULL)
		return (-1);
	*v->result = NULL;
	v->tmp = NULL;
	return (0);
}

static char	*get_chank(char const *s, size_t start, size_t stop)
{
	char	*result;
	size_t	i;

	result = NULL;
	i = stop - start + 1;
	result = (char *)malloc(sizeof(*s) * i);
	if (result == NULL)
		return (result);
	*(result + --i) = '\0';
	while (i--)
	{
		*(result + i) = *(s + start + i);
	}
	return (result);
}

static int	append(char ***arr, char **str, int ind)
{
	char	**temp;
	int		i;

	i = ind;
	temp = NULL;
	temp = (char **)malloc(sizeof(*arr) * (i + 2));
	if (NULL == temp)
	{
		array_free(arr);
		return (-1);
	}
	*(temp + i + 1) = NULL;
	*(temp + i) = *str;
	while (i-- != 0)
	{
		*(temp + i) = *(*arr + i);
	}
	free(*arr);
	*arr = temp;
	return (0);
}

static void	array_free(char ***arr)
{
	int	i;

	i = 0;
	while (*(*arr + i) != NULL)
	{
		free(*(*arr + i));
		*(*arr + i) = NULL;
		i++;
	}
	*arr = NULL;
	free(*arr);
}
