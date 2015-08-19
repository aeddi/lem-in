/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xwindow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:24:21 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 15:26:17 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include <xstruct.h>

void	clear_window(t_xdata *data)
{
	XClearWindow(data->display, data->window);
}

void	set_background_color(t_xdata *data, int r, int g, int b)
{
	XColor					color;
	XSetWindowAttributes	attr;

	color.pixel = 0;
	color.red = r << 8;
	color.green = g << 8;
	color.blue = b << 8;
	XAllocColor(data->display, data->colormap, &color);
	attr.background_pixel = color.pixel;
	XChangeWindowAttributes(data->display, data->window, CWBackPixel, &attr);
}
