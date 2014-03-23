#include <lem-in.h>
#include <libft.h>

void	display_pipe(t_graph *root)
{
	size_t	i;

	i = 0;
	while (root)
	{
		while (root->tab[i])
		{
			if (root->tab[i]->taken == 0)
			{
				ft_putstr(root->name);
				ft_putchar('-');
				ft_putendl(root->tab[i]->name);
			}
			i++;
		}
		root->taken = 1;
		root = root->list;
	}
}

void	display_map(t_graph *root, size_t f_nb)
{
	t_graph	*tmp;

	ft_putnbr(f_nb);
	ft_putchar('\n');
	tmp = root;
	while (tmp)
	{
		ft_putstr(tmp->name);
		ft_putnbr(tmp->x_coor);
		ft_putnbr(tmp->y_coor);
		ft_putchar('\n');
		tmp = tmp->list;
	}
	display_pipe(root);
}

void	display_run(size_t f_n, char *room)
{
	ft_putchar('L');
	ft_putnbr(f_n);
	ft_putchar('-');
	ft_putstr(room);
}

void	calc_process(t_graph *root, size_t f_nb, size_t i)
{
	/*
	char	**way;

	way = choose_way(root)
	*/
	display_map(root, f_nb);
i = 0;
i++;
	/*
	while (i)
	{
	}
	*/
}
