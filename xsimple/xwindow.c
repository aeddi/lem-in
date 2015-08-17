/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xwindow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 01:20:52 by plastic           #+#    #+#             */
/*   Updated: 2015/08/17 01:41:35 by plastic          ###   ########.fr       */
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
	XColor color;
	XSetWindowAttributes attr;

	color.pixel = 0;
	color.red = r << 8;
	color.green = g << 8;
	color.blue = b << 8;
	XAllocColor(data->display, data->colormap, &color);
	attr.background_pixel = color.pixel;
	XChangeWindowAttributes(data->display, data->window, CWBackPixel, &attr);
}
