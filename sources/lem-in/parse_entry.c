/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 20:35:29 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 15:10:38 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem-in.h>
#include <libft.h>

t_bool	check_room(t_graph *root)
{
	int		check_end;
	int		check_start;
	t_graph	*tmp;

	tmp = root;
	check_end = 0;
	check_start = 0;
	while (tmp)
	{
		if (tmp->type == END)
			check_end++;
		if (tmp->type == START)
			check_start++;
		tmp = tmp->list;
	}
	if (check_start == 1 && check_end == 1)
		return (TRUE);
	return (FALSE);
}

t_graph	*parse_room(char **save, char **total)
{
	t_node	stat;
	t_graph	*ret;
	char	**sp;

	read_line(save, 0, &stat, total);
	if (*save)
	{
		sp = ft_strsplit(*save, ' ');
		if (ft_tablen(sp) != 3 || ft_strchr(sp[0], '-')
			|| check_num(sp[1]) == FALSE || check_num(sp[2]) == FALSE)
		{
			sp = ft_tabdel(sp);
			return (NULL);
		}
		ret = new_node(stat, ft_strdup(sp[0]), ft_atoi(sp[1]), ft_atoi(sp[2]));
		sp = ft_tabdel(sp);
		ft_strdel(save);
		return (ret);
	}
	return (NULL);
}

t_bool	connect_room(t_graph **root, char *room1, char *room2)
{
	t_graph	*tmp1;
	t_graph	*tmp2;

	tmp1 = *root;
	tmp2 = tmp1;
	while (tmp1)
	{
		if (ft_strcmp(tmp1->name, room1) == 0)
			break ;
		tmp1 = tmp1->list;
	}
	while (tmp2)
	{
		if (ft_strcmp(tmp2->name, room2) == 0)
			break ;
		tmp2 = tmp2->list;
	}
	if (!tmp2 || !tmp1)
		return (FALSE);
	tabadd(tmp1, tmp2);
	tabadd(tmp2, tmp1);
	return (TRUE);
}

void	make_connection(t_graph **root, char *save, char **total)
{
	char	**sp;
	t_node	stat;
	char	*tmp;

	while (42)
	{
		sp = ft_strsplit(save, '-');
		free(save);
		save = NULL;
		if (ft_tablen(sp) != 2 || connect_room(root, sp[0], sp[1]) == FALSE)
		{
			sp = ft_tabdel(sp);
			return ;
		}
		sp = ft_tabdel(sp);
		read_line(&save, 0, &stat, total);
		if (!save)
		{
			tmp = *total;
			*total = ft_strjoin(*total, "\n");
			free(tmp);
			break ;
		}
	}
}

void	parse_entry(t_graph **root, char **total)
{
	t_graph	*tmp;
	t_graph	*tmp2;
	char	*save;

	save = NULL;
	*root = NULL;
	tmp = NULL;
	while (42)
	{
		if (!(tmp2 = parse_room(&save, total)))
			break ;
		if (!*root)
		{
			*root = tmp2;
			tmp = tmp2;
		}
		else
		{
			tmp->list = tmp2;
			tmp = tmp->list;
		}
	}
	if (check_room(*root) == FALSE || !save)
		exit_error(*root);
	make_connection(root, save, total);
}
