/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:57:00 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/11 19:00:43 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_coord		***tetraminos;
	char		*input;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	if (!(input = file_read(open(argv[1], O_RDONLY), argv[1])) || \
		!check_input(input))
	{
		ft_putstr("error\n");
		return (0);
	}
	tetraminos = get_coords(input);
	if (tetraminos)
	{
		solve(tetraminos);
		return (0);
	}
	ft_putstr("error\n");
	return (2);
}

void	free_tetra(t_coord ***tetra, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < 4)
			free(tetra[i][j++]);
		free(tetra[i]);
		i++;
	}
	free(tetra[i]);
	free(tetra);
}
