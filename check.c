/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:24:54 by mfrankev          #+#    #+#             */
/*   Updated: 2016/12/11 18:57:44 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set_to_zero(int *i, int *c_n, int *c_b)
{
	*c_b = 0;
	*c_n = 0;
	*i = 0;
}

int				check_input(char *in)
{
	int c_b;
	int c_n;
	int i;

	i = 0;
	c_n = 0;
	c_b = 0;
	while (*in && (*in == '.' || *in == '#' || *in == '\n') && i < 20)
	{
		if (*in == '.' && in++ && ++i)
			continue ;
		else if (*in == '#' && in++ && ++i && ++c_b)
			continue ;
		else if (*in == '\n' && in++ && ++i && ++c_n)
			if (i % 5 != 0)
				return (0);
		if (*in == '\n' && in[1])
		{
			if (c_b == 4 && c_n == 4 && i == 20 && in++)
				set_to_zero(&i, &c_n, &c_b);
			else if (*in)
				return (0);
		}
	}
	return (*in ? 0 : 1);
}
