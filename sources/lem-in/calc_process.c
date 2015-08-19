/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:08:07 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 15:08:28 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>
#include <libft.h>

void	add_way(t_wlst **root, char *way, size_t len)
{
	t_wlst	*tmp;

	tmp = *root;
	if (*root == NULL)
		*root = new_wlst(len, way);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_wlst(len, way);
	}
}

void	find_way(t_graph *node, t_wlst **root, char *way, size_t depth)
{
	size_t	i;
	char	*n_way;

	i = 0;
	node->taken = TRUE;
	n_way = (way) ? ft_strjoin_tw(way, " ", node->name) : node->name;
	if (node->type == END)
		add_way(root, n_way, depth);
	else
	{
		while (node->tab && node->tab[i])
		{
			if (node->tab[i]->taken == FALSE)
				find_way(node->tab[i], root, n_way, depth + 1);
			i++;
		}
		if (way)
			free(n_way);
	}
	node->taken = FALSE;
}

t_wlst	*choose_way(t_graph *root)
{
	t_wlst	*w_root;

	w_root = NULL;
	while (root->type != START)
		root = root->list;
	find_way(root, &w_root, NULL, 1);
	return (w_root);
}

void	calc_process(t_graph *root, size_t ant_nb)
{
	t_wlst	*way;
	t_wlst	*tmp;
	t_wlst	*best_way;

	way = choose_way(root);
	best_way = way;
	tmp = way;
	if (!way)
	{
		ft_putendl("No existing path");
		free_graph(root);
		exit(0);
	}
	while (tmp)
	{
		best_way = (best_way->len <= tmp->len) ? best_way : tmp;
		tmp = tmp->next;
	}
	display_result(best_way, ant_nb);
	free_wlst(way);
}
