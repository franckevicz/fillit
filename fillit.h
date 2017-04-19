/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:02:57 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/09 14:43:00 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_coord
{
	int		x;
	int		y;
	char	alpha;
}				t_coord;

void			ft_putchar(char c);
void			ft_putstr(char const *s);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
void			free_tetra(t_coord ***tetra, int n);
void			free_map(char **map, int map_size);
void			remove_tetra(int y, int x, char **map, t_coord **tetra);
int				check_place(int y, int x, char **map, t_coord **tetra);
int				place(int y, int x, char **map, t_coord **tetra);
int				fill_it(char **map, t_coord ***tetra, int map_size, int n);
void			solve(t_coord ***tetra);
void			print_result(char **map, int map_size);
int				count_elem(char *input);
void			arrange(t_coord **coords);
t_coord			**make_coords(char **tet, char c);
t_coord			***get_coords(char *input);
int				abs(int n);
t_coord			**coords_mem(void);
int				check_coords(t_coord **coords);
char			*file_read(int fd, char *filename);
char			***parse(char *input, int elem);
int				ft_sqrt(int nb);
int				check_input(char *input);
char			***make_alpha(char ***tetra);
char			**gen_map(int n);
int				can_put_tetra(char **map, int y, int x, char **tetra);

#endif
