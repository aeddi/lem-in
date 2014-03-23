#include <lem-in.h>
#include <libft.h>

void	display_pipe(t_graph *root)
{
	size_t	i;
	t_graph	*tmp;

	i = 0;
	tmp = root;
	while (tmp)
	{
		while (tmp->tab[i])
		{
			if (tmp->tab[i]->taken == 0)
			{
				ft_putstr(tmp->name);
				ft_putchar('-');
				ft_putendl(tmp->tab[i]->name);
			}
			i++;
		}
		tmp->taken = 1;
		tmp = tmp->list;
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
		if (tmp->type == START)
			ft_putendl("##start");
		if (tmp->type == END)
			ft_putendl("##end");
		ft_putstr(tmp->name);
		ft_putchar(' ');
		ft_putnbr(tmp->x_coor);
		ft_putchar(' ');
		ft_putnbr(tmp->y_coor);
		ft_putchar('\n');
		tmp = tmp->list;
	}
	display_pipe(root);
	ft_putchar('\n');
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
