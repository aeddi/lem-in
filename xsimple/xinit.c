/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xinit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 01:23:23 by plastic           #+#    #+#             */
/*   Updated: 2015/08/17 01:40:42 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include <xstruct.h>
#include <libft.h>
#include <stdlib.h>

static Display	*get_display(void)
{
	Display *new;
	
	new = XOpenDisplay(0);
	if (!new)
	{
		ft_putendl_fd("X11: unable to open the graphics window.", 2);
		return NULL;
	}
	return new;
}

static int		get_color_mode(Display *display)
{
	Visual	*visual;

	visual = DefaultVisual(display, 0);
	if (visual && visual->class == TrueColor)
		return 1;
	else
		return 0;
}

static void		get_window(char *title, int width, int height, t_xdata *data)
{
	int						black;
	int						white;
	XSetWindowAttributes	attr;

	black = BlackPixel(data->display, DefaultScreen(data->display));
	white = WhitePixel(data->display, DefaultScreen(data->display));
	data->window = XCreateSimpleWindow(data->display,
		DefaultRootWindow(data->display), 0, 0, width, height, 0, black, black);
	attr.backing_store = Always;
	XChangeWindowAttributes(data->display, data->window, CWBackingStore, &attr);
	XStoreName(data->display, data->window, title);
	XSelectInput(data->display, data->window,
					StructureNotifyMask|KeyPressMask|ButtonPressMask);
	XMapWindow(data->display, data->window);
	data->gc = XCreateGC(data->display, data->window, 0, 0);
	data->colormap = DefaultColormap(data->display, 0);
	XSetForeground(data->display, data->gc, white);
}

t_xdata			*init_x_window(char *title, int width, int height)
{
	t_xdata		*data;
	XEvent		event;

	data = (t_xdata *)malloc(sizeof(t_xdata));
	if ((data->display = get_display()))
	{
		data->colormode = get_color_mode(data->display);
		get_window(title, width, height, data);
		while (42)
		{
			XNextEvent(data->display, &event);
			if (event.type == MapNotify)
				break;
		}
		return data;
	}
	else
		return NULL;
}
