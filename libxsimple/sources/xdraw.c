/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdraw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:22:38 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 16:07:16 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include <xfunctions.h>
#include <xstruct.h>

void	draw_point(t_xdata *data, t_vector_2 point)
{
	XDrawPoint(data->display, data->window, data->gc, point.x, point.y);
}

void	draw_line(t_xdata *data, t_vector_2 start, t_vector_2 end)
{
	XDrawLine(data->display, data->window, data->gc,
				start.x, start.y, end.x, end.y);
}

void	draw_rectangle(t_xdata *data, t_vector_2 ul, t_vector_2 sz, short fill)
{
	if (fill)
		XFillRectangle(data->display, data->window, data->gc,
						ul.x, ul.y, sz.x, sz.y);
	else
		XDrawRectangle(data->display, data->window, data->gc,
						ul.x, ul.y, sz.x, sz.y);
}

void	draw_text(t_xdata *data, t_vector_2 point, char *text)
{
	int			direction;
	int			ascent;
	int			descent;
	XCharStruct	overall;

	XTextExtents(data->font, text, ft_strlen(text),
					&direction, &ascent, &descent, &overall);
	point.y += ascent + 1 - descent;
	XDrawString(data->display, data->window, data->gc,
				point.x, point.y, text, ft_strlen(text));
}

void	set_drawing_color(t_xdata *data, int r, int g, int b)
{
	XColor color;

	if (data->colormode)
		color.pixel = ((b & 0xff) | ((g & 0xff) << 8) | ((r & 0xff) << 16));
	else
	{
		color.pixel = 0;
		color.red = r << 8;
		color.green = g << 8;
		color.blue = b << 8;
		XAllocColor(data->display, data->colormap, &color);
	}
	XSetForeground(data->display, data->gc, color.pixel);
}
