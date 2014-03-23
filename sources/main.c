#include <lem-in.h>
#include <stdlib.h>
#include <libft.h>

void	exit_error(t_graph *root)
{
	if (root)
		free_graph(root);
	ft_putendl("ERROR");
	exit(1);
}

t_bool	check_num(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (!ft_isdigit(buf[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int				main(void)
{
	t_graph	*root;
	t_node	stat;
	size_t	f_nb;
	char	*buf;

	read_line(&buf, 0, &stat);
	if (buf && stat == NORMAL && check_num(buf) == TRUE)
	{
		f_nb = ft_atoi(buf);
		free(buf);
	}
	else
		exit_error(NULL);
	if (f_nb == 0)
		exit_error(NULL);
	parse_entry(&root);
	calc_process(root, f_nb, 0);
	free_graph(root);
	return (0);
}
