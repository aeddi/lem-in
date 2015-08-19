/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 19:12:09 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 15:07:55 by aeddi            ###   ########.fr       */
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

int		main(void)
{
	t_graph	*root;
	t_node	stat;
	size_t	ant_nb;
	char	*total;

	total = NULL;
	ant_nb = 0;
	read_line(&total, 0, &stat, NULL);
	if (total)
	{
		if (stat == NORMAL && check_num(total) == TRUE && ft_atoi(total) > 0)
			ant_nb = ft_atoi(total);
		else
		{
			free(total);
			exit_error(NULL);
		}
		parse_entry(&root, &total);
		ft_putendl(total);
		free(total);
		calc_process(root, ant_nb);
		free_graph(root);
		return (0);
	}
	exit_error(NULL);
}
