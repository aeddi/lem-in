/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 16:25:24 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 16:25:25 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <lem-in-struct.h>

t_bool	check_num(char *buf);
void	exit_error(t_graph *root);
void	read_line(char **buf, int ret, t_node *stat, char **total);
void	parse_entry(t_graph **root, char **total);
void	calc_process(t_graph *root, size_t ant_nb);
void	free_graph(t_graph *root);
t_graph	*new_node(t_node type, char *name, long long x_coor, long long y_coor);
void	tabadd(t_graph *tab, t_graph *entry);
size_t	tabsize(t_graph **tab);
char	**ft_tabdel(char **tab);
void	display_run(size_t ant_n, char *room);
void	display_pipe(t_graph *root);
t_wlst	*new_wlst(size_t len, char *way);
void	free_wlst(t_wlst *root);
void	display_result(t_wlst *best, size_t ant_nb);

#endif
