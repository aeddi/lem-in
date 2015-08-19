/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 19:12:02 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 13:42:19 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>
#include <stdlib.h>

void	free_graph(t_graph *root)
{
	t_graph	*tmp;

	while (root)
	{
		tmp = root;
		root = root->list;
		free(tmp->name);
		free(tmp->tab);
		free(tmp);
	}
}

void	free_wlst(t_wlst *root)
{
	t_wlst	*tmp;

	while (root)
	{
		tmp = root;
		root = root->next;
		free(tmp->way);
		free(tmp);
	}
}
