/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 22:52:16 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 15:03:28 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>
#include <stdio.h>
#include <libft.h>

void	save_total(char *buf, char **total)
{
	char	*tmp;

	if (buf && total)
	{
		tmp = *total;
		*total = ft_strjoin_tw(*total, "\n", buf);
		free(tmp);
	}
}

void	read_line(char **buf, int ret, t_node *stat, char **total)
{
	*stat = NORMAL;
	while (42)
	{
		if (*buf)
			free(*buf);
		ret += get_next_line(0, buf);
		if (ret == 0 || (*buf && *buf[0] == 'L') || !ft_strlen(*buf))
		{
			if (*buf)
				ft_strdel(buf);
		}
		else if (ret == -1)
		{
			perror("Read line: ");
			exit(1);
		}
		save_total(*buf, total);
		if (*buf && *buf[0] && *buf[0] == '#')
		{
			*stat = (ft_strcmp(*buf, "##end") == 0) ? END : *stat;
			*stat = (ft_strcmp(*buf, "##start") == 0) ? START : *stat;
			continue ;
		}
		break ;
	}
}
