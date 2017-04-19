/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:06:33 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/11 19:07:45 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char		*file_read(int fd, char *filename)
{
	int		i;
	char	*out;

	i = 0;
	if (fd == -1)
		return (NULL);
	while (read(fd, &out, 1) > 0)
		i++;
	if (!(out = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	close(fd);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	read(fd, out, i);
	out[i] = '\0';
	return (out);
}

static char	**add_tetra(char **input, int i, int j)
{
	char **tetra;
	char *tmp;

	tmp = *input;
	if (!(tetra = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (*input - tmp < 20 && **input && i < 4)
	{
		if (!(tetra[i] = ft_strnew(5)))
			return (NULL);
		j = 0;
		while (j < 4 && **input)
		{
			tetra[i][j++] = *tmp++;
		}
		tmp++;
		i++;
	}
	tetra[i] = NULL;
	if (*tmp)
		*input = ++tmp;
	else
		*input = tmp;
	return (tetra);
}

char		***parse(char *input, int elem)
{
	int		i;
	int		j;
	int		k;
	char	***tetra;

	i = 0;
	j = 0;
	k = elem - 1;
	if (!(tetra = (char ***)malloc(sizeof(char **) * (elem + 2))))
		return (NULL);
	tetra[elem] = NULL;
	while (k > -1)
	{
		tetra[k] = add_tetra(&input, i, j);
		k--;
	}
	return (tetra);
}

int			count_elem(char *input)
{
	int i;
	int n;

	n = 1;
	i = 1;
	while (input[i])
	{
		if (input[i] == '\n' && input[i - 1] == '\n')
			n++;
		i++;
	}
	return (n > 1 ? n : -1);
}

t_coord		***get_coords(char *input)
{
	char		***tetra;
	t_coord		***coords;
	int			elems;
	int			i;

	i = 0;
	elems = count_elem(input);
	if (elems > 26 && elems < 0)
		return (0);
	tetra = parse(input, elems);
	if (!(coords = (t_coord***)malloc(sizeof(t_coord**) * elems + 1)))
		return (0);
	while (i < elems)
	{
		if (!(coords[i] = make_coords(tetra[i], ('A' + elems - i - 1))))
			return (0);
		if (!(check_coords(coords[i])))
			return (0);
		i++;
	}
	coords[i] = NULL;
	return (coords);
}
