/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:08:16 by aeddi             #+#    #+#             */
/*   Updated: 2014/03/23 22:46:41 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdlib.h>

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef	enum	e_node
{
	START,
	END,
	NORMAL
}				t_node;

typedef struct		s_graph
{
	t_node			type;
	char			*name;
	int				x_coor;
	int				y_coor;
	t_bool			taken;
	struct s_graph	*list;
	struct s_graph	**tab;
}					t_graph;

typedef	struct		s_wlst
{
	size_t			len;
	char			*way;
	struct s_wlst	*next;
}					t_wlst;

t_bool	check_num(char *buf);
void	exit_error(t_graph *root);
void	read_line(char **buf, int ret, t_node *stat);
void	parse_entry(t_graph **root);
void	calc_process(t_graph *root, size_t ant_nb);
void	free_graph(t_graph *root);
t_graph	*new_node(t_node type, char *name, long long x_coor, long long y_coor);
void	tabadd(t_graph *tab, t_graph *entry);
size_t	tabsize(t_graph **tab);
char	**ft_tabdel(char **tab);
void	display_run(size_t ant_n, char *room);
void	display_map(t_graph *root, size_t ant_nb);
void	display_pipe(t_graph *root);
t_wlst	*new_wlst(size_t len, char *way);
void	free_wlst(t_wlst *root);
void	display_result(t_wlst *best, size_t ant_nb);

#endif /* !LEM_IN_H */
