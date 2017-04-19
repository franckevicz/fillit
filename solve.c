/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:29:05 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/11 19:08:54 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(t_coord ***tetra)
{
	char	**map;
	int		n;
	int		map_size;

	n = 0;
	while (tetra[n])
		n++;
	map_size = ft_sqrt(n * 4);
	map = gen_map(map_size);
	while (!(fill_it(map, tetra, map_size, n)))
	{
		free_map(map, map_size);
		map_size++;
		map = gen_map(map_size);
	}
	print_result(map, map_size);
	free_tetra(tetra, n);
}

int		fill_it(char **map, t_coord ***tetra, int map_size, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (n == 0)
		return (1);
	while (i < map_size)
	{
		j = 0;
		while (j <= map_size)
		{
			if (place(i, j, map, tetra[n - 1]))
			{
				if (!(fill_it(map, tetra, map_size, n - 1)))
					remove_tetra(i, j, map, tetra[n - 1]);
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		place(int y, int x, char **map, t_coord **tetra)
{
	int i;

	i = 0;
	if (!(check_place(y, x, map, tetra)))
		return (0);
	while (i < 4)
	{
		map[y + (tetra[i])->y][x + (tetra[i])->x] = (tetra[i])->alpha;
		i++;
	}
	return (1);
}

int		check_place(int y, int x, char **map, t_coord **tetra)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(map[0]);
	while (i < 4)
	{
		if ((tetra[i])->y + y >= n || (tetra[i])->x + x >= n)
			return (0);
		if (map[(tetra[i])->y + y][(tetra[i])->x + x] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	remove_tetra(int y, int x, char **map, t_coord **tetra)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[y + (tetra[i])->y][x + (tetra[i])->x] = '.';
		i++;
	}
}
