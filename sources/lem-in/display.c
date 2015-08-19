/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:08:32 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 13:56:32 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lem-in.h>

void	display_pipe(t_graph *root)
{
	size_t	i;
	t_graph	*tmp;

	tmp = root;
	while (tmp)
	{
		if (tmp->tab)
		{
			i = 0;
			while (tmp->tab && tmp->tab[i])
			{
				if (tmp->tab[i]->taken == 0)
				{
					ft_putstr(tmp->name);
					ft_putchar('-');
					ft_putendl(tmp->tab[i]->name);
				}
				i++;
			}
		}
		tmp->taken = 1;
		tmp = tmp->list;
	}
}

void	display_run(size_t ant_n, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant_n);
	ft_putchar('-');
	ft_putstr(room);
}

void	display_line(char **tab, size_t round, size_t len, size_t ant_nb)
{
	size_t	first;
	size_t	ant_n;
	size_t	room;
	size_t	total;

	first = 0;
	ant_n = (round < len) ? 1 : round - len + 2;
	room = (round < len) ? round : len - 1;
	total = ant_nb;
	while (room && total)
	{
		if (ant_n > ant_nb)
			break ;
		if (first)
			ft_putchar(' ');
		first++;
		display_run(ant_n, tab[room]);
		ant_n++;
		room--;
		total--;
	}
}

void	display_result(t_wlst *best, size_t ant_nb)
{
	char	**tab;
	size_t	i;

	tab = ft_strsplit(best->way, ' ');
	i = 0;
	while (i < best->len + ant_nb)
	{
		display_line(tab, i, best->len, ant_nb);
		i++;
		if (i > 1 && i < best->len + ant_nb)
			ft_putchar('\n');
	}
	tab = ft_tabdel(tab);
}
