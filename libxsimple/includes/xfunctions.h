/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xfunctions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:24:03 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 16:06:56 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XFUNCTIONS_H
# define XFUNCTIONS_H

# include <xstruct.h>
# include <stdlib.h>

# define BLACK	0x00, 0x00, 0x00
# define WHITE	0xFF, 0xFF, 0xFF
# define GREY	0x80, 0x80, 0x80
# define RED	0xFF, 0x00, 0x00
# define GREEN	0x00, 0xFF, 0x00
# define BLUE	0x00, 0x00, 0xFF
# define YELLOW	0xFF, 0xFF, 0x00
# define CYAN	0x00, 0xFF, 0xFF
# define VIOLET	0xFF, 0x00, 0xFF
# define ORANGE	0xFF, 0x80, 0x00

t_xdata	*init_x_window(char *title, int width, int height, char *font);

/*
**	Drawing functions
*/
void	draw_point(t_xdata *data, t_vector_2 point);
void	draw_line(t_xdata *data, t_vector_2 start, t_vector_2 end);
void	draw_rectangle(t_xdata *data, t_vector_2 ul, t_vector_2 dr, short fill);
void	draw_text(t_xdata *data, t_vector_2 point, char *text);
void	set_drawing_color(t_xdata *data, int r, int g, int b);

/*
**	Event functions
*/
int		wait_any_event(t_xdata *data);
char	wait_input(t_xdata *data);

/*
**	Window functions
*/
void	clear_window(t_xdata *data);
void	set_background_color(t_xdata *data, int r, int g, int b);

/*
**	Aux functions
*/
void	ft_putendl_fd(char const *s, int fd);
size_t	ft_strlen(const char *s);

#endif
