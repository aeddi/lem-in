/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 16:25:35 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 16:25:44 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCT_H
# define LEM_IN_STRUCT_H

# include <stdlib.h>

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef	enum		e_node
{
	START,
	END,
	NORMAL
}					t_node;

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

#endif
