/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdraw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 01:19:31 by plastic           #+#    #+#             */
/*   Updated: 2015/08/17 01:38:34 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
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
