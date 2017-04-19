/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:35:42 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/11 19:10:56 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int tmp;

	tmp = 1;
	if (nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	while (42)
	{
		if (tmp * tmp == nb || tmp * tmp > nb)
		{
			return (tmp);
		}
		tmp++;
	}
	return (0);
}

char	**gen_map(int n)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * n)))
		return (NULL);
	while (i < n)
	{
		j = 0;
		if (!(map[i] = (char*)malloc(sizeof(char) * (n + 1))))
			return (0);
		while (j < n)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

int		can_put_tetra(char **map, int y, int x, char **tetra)
{
	int i;
	int j;
	int side;
	int count;

	count = 0;
	i = 0;
	side = ft_strlen(map[i]);
	while (i < 4 && (i + y) < side)
	{
		j = 0;
		while (j < 4 && (j + x) < side)
		{
			if (tetra[i][j] != '.')
			{
				count++;
				if (!(map[y + i][x + j]) || !(map[y + i][x + j] == '.'))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (count == 4 ? 1 : 0);
}

void	print_result(char **map, int map_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map_size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_map(char **map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
		free(map[i++]);
	free(map);
}
