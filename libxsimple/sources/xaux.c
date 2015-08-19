/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xaux.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 15:24:43 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 15:29:10 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putendl_fd(char const *s, int fd)
{
	char	c;

	c = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &c, 1);
}
