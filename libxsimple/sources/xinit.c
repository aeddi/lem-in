/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xinit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:23:54 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 16:07:32 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include <xfunctions.h>
#include <xstruct.h>
#include <stdlib.h>

static Display	*get_display(void)
{
	Display *new;

	new = XOpenDisplay(0);
	if (!new)
	{
		ft_putendl_fd("X11: unable to open the graphics window.", 2);
		return (NULL);
	}
	return (new);
}

static int		get_color_mode(Display *display)
{
	Visual	*visual;

	visual = DefaultVisual(display, 0);
	if (visual && visual->class == TrueColor)
		return (1);
	else
		return (0);
}

static void		get_font(char *fontname, t_xdata *data)
{
	data->font = NULL;
	if (fontname)
		data->font = XLoadQueryFont(data->display, fontname);
	if (!data->font)
	{
		if (fontname)
			ft_putendl_fd("Unable to load specified font: using fixed", 2);
		data->font = XLoadQueryFont(data->display, "fixed");
	}
	XSetFont(data->display, data->gc, data->font->fid);
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
					StructureNotifyMask | KeyPressMask | ButtonPressMask);
	XMapWindow(data->display, data->window);
	data->gc = XCreateGC(data->display, data->window, 0, 0);
	data->colormap = DefaultColormap(data->display, 0);
	XSetForeground(data->display, data->gc, white);
}

t_xdata			*init_x_window(char *title, int width, int height, char *font)
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
				break ;
		}
		get_font(font, data);
		return (data);
	}
	else
		return (NULL);
}
