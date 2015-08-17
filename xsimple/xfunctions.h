/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xfunctions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 01:37:18 by plastic           #+#    #+#             */
/*   Updated: 2015/08/17 01:49:32 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XFUNCTIONS_H
# define XFUNCTIONS_H

# include <xstruct.h>

t_xdata	*init_x_window(char *title, int width, int height);

/*
 *	Drawing functions
 */
void	set_drawing_color(t_xdata *data, int r, int g, int b);
void	draw_point(t_xdata *data, t_vector_2 point);
void	draw_line(t_xdata *data, t_vector_2 start, t_vector_2 end);

/*
 *	Event functions
 */
int		wait_any_event(t_xdata *data);
char	wait_input(t_xdata *data);

/*
 *	Window functions
 */
void	clear_window(t_xdata *data);
void	set_background_color(t_xdata *data, int r, int g, int b);

#endif /* !XFUNCTIONS_H */
