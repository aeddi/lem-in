/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 19:11:56 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 13:42:44 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <lem-in.h>

t_graph	*new_node(t_node type, char *name, long long x_coor, long long y_coor)
{
	t_graph	*new;

	new = (t_graph *)malloc(sizeof(t_graph));
	new->type = type;
	new->name = name;
	new->x_coor = x_coor;
	new->y_coor = y_coor;
	new->taken = FALSE;
	new->list = NULL;
	new->tab = NULL;
	return (new);
}

t_wlst	*new_wlst(size_t len, char *way)
{
	t_wlst	*new;

	new = (t_wlst *)malloc(sizeof(t_wlst));
	new->len = len;
	new->way = way;
	new->next = NULL;
	return (new);
}

size_t	tabsize(t_graph **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

void	tabadd(t_graph *tab, t_graph *entry)
{
	t_graph	**new;
	size_t	i;

	i = 0;
	new = (t_graph **)malloc(sizeof(t_graph *) * (tabsize(tab->tab) + 2));
	if (tab->tab)
	{
		while (tab->tab[i])
		{
			new[i] = tab->tab[i];
			i++;
		}
		free(tab->tab);
	}
	new[i] = entry;
	new[i + 1] = NULL;
	tab->tab = new;
}
