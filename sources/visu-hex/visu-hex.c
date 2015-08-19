/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu-hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:22:22 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 14:24:52 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <xfunctions.h>
#include <visu-hex.h>

static void	main_loop(t_xdata *session, t_room *rooms, t_link *links)
{
	char			c;
	unsigned int	turn;

	c = 0;
	turn = 1;
	while (42)
	{
		if (c != 'q')
		{
			/* if (update_state(rooms)) */
			/* 	return ; */
			clear_window(session);
			print_turn(turn);
			print_links(links);
			print_rooms(rooms);
			turn++;
		}
		else
			return ;
		c = wait_input(session);
	}
}

int			main(void)
{
	t_xdata	*session;
	t_room	*rooms;
	t_link	*links;
	char	*buf;

	session = init_x_window("Lem-in", 1500, 1000, "-*-*-bold-r-*-*-15-*");
	if (!session)
		return (1);
	rooms = get_rooms(&buf);
	if (!rooms)
		return (1);
	links = get_links(&buf);
	if (!links)
		return (1);
	set_background_color(session, GREY);
	main_loop(session, rooms, links);
	free_data(session, rooms, links);
	return (0);
}
