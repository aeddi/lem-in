/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 19:12:09 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/17 02:43:09 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>
#include <stdlib.h>
#include <libft.h>

void	exit_error(t_graph *root)
{
	if (root)
		free_graph(root);
	ft_putendl("ERROR");
	exit(1);
}

t_bool	check_num(char *buf)
{
	size_t	i;

	i = 0;
	if (buf[i] == '-')
		i++;
	while (buf[i])
	{
		if (!ft_isdigit(buf[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int				main(void)
{
	t_graph	*root;
	t_node	stat;
	size_t	ant_nb;
	char	*buf;

	buf = NULL;
	read_line(&buf, 0, &stat);
	if (buf && stat == NORMAL && check_num(buf) == TRUE && ft_atoi(buf) >= 0)
	{
		ant_nb = ft_atoi(buf);
		free(buf);
	}
	else
		exit_error(NULL);
	if (ant_nb <= 0)
		exit_error(NULL);
	parse_entry(&root);
	calc_process(root, ant_nb);
	free_graph(root);
	return (0);
}
