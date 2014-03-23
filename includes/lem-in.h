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
	long long		x_coor;
	long long		y_coor;
	t_bool			taken;
	struct s_graph	*list;
	struct s_graph	**tab;
}					t_graph;

t_bool	check_num(char *buf);
void	exit_error(t_graph *root);
void	read_line(char **buf, int ret, t_node *stat);
void	parse_entry(t_graph **root);
void	calc_process(t_graph *root, size_t f_nb, size_t i);
void	free_graph(t_graph *root);
t_graph	*new_node(t_node type, char *name, long long x_coor, long long y_coor);
t_graph	**tabadd(t_graph **tab, t_graph *room);
size_t	tabsize(t_graph **tab);

#endif /* !LEM_IN_H */
