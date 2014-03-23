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
