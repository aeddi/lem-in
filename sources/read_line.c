#include <lem-in.h>
#include <stdio.h>
#include <libft.h>

void	read_line(char **buf, int ret, t_node *stat)
{
	*stat = NORMAL;
	while (42)
	{
		if (*buf)
			free(*buf);
		ret += get_next_line(0, buf);
		if (ret == 0 || (*buf && *buf[0] == 'L') || !ft_strlen(*buf))
		{
			if (*buf)
				free(*buf);
			*buf = NULL;
		}
		else if (ret == -1)
		{
			perror("Read line: ");
			exit(1);
		}
		if (*buf && *buf[0] && *buf[0] == '#')
		{
			*stat = (ft_strcmp(*buf, "##end") == 0) ? END : *stat;
			*stat = (ft_strcmp(*buf, "##start") == 0) ? START : *stat;
			continue ;
		}
		break ;
	}
}
