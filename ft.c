/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohesheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:45:22 by ohesheli          #+#    #+#             */
/*   Updated: 2016/12/12 14:45:23 by ohesheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

size_t	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	i = 0;
	while (i <= size)
		str[i++] = 0;
	return (str);
}
