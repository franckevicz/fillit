/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_one_tetra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:32:11 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/11 19:09:35 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord		**make_coords(char **tet, char c)
{
	t_coord		**coords;
	int			i;
	int			j;
	int			k;

	i = -1;
	k = 0;
	if (!(coords = coords_mem()))
		return (0);
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tet[i][j] == '#')
			{
				(coords[k])->y = i;
				(coords[k])->alpha = c;
				(coords[k++])->x = j;
			}
			j++;
		}
	}
	arrange(coords);
	return (coords);
}

void		arrange(t_coord **coords)
{
	int y;
	int x;
	int i;

	y = 3;
	x = 3;
	i = 0;
	while (i < 4)
	{
		if ((coords[i])->x < x)
			x = (coords[i])->x;
		if ((coords[i])->y < y)
			y = (coords[i])->y;
		i++;
	}
	if (y == 0 && x == 0)
		return ;
	i = 0;
	while (i < 4)
	{
		(coords[i])->y = (coords[i])->y - y;
		(coords[i])->x = (coords[i])->x - x;
		i++;
	}
}

int			check_coords(t_coord **coords)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	j = 0;
	counter = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != j)
			{
				if ((abs((coords[i])->x - (coords[j])->x) \
					+ abs((coords[i])->y - (coords[j])->y)) == 1)
					counter++;
			}
			j++;
		}
		i++;
	}
	if (counter < 6)
		return (0);
	return (1);
}

int			abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_coord		**coords_mem(void)
{
	t_coord		**coords;
	int			i;

	i = 0;
	if (!(coords = (t_coord**)malloc(sizeof(t_coord*) * 4)))
		return (0);
	while (i < 4)
	{
		if (!(coords[i] = (t_coord*)malloc(sizeof(t_coord))))
			return (0);
		i++;
	}
	return (coords);
}
