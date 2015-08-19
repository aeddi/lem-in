/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_hex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:21:40 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 14:25:44 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_HEX_H
# define VISU_HEX_H

typedef enum		e_room_type
{
	START,
	END,
	NORMAL
}					t_room_type;

typedef struct		s_room
{
	char			*name;
	int				x_pos;
	int				y_pos;
	int				ant_n;
	t_room_type		type;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	t_room			*start;
	t_room			*end;
	struct e_link	*next;
}					t_link;

#endif
