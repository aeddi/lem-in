/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xevent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 01:16:49 by plastic           #+#    #+#             */
/*   Updated: 2015/08/17 01:57:49 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include <xstruct.h>

int		wait_any_event(t_xdata *data)
{
	XEvent event;

	XFlush(data->display);
	while(42)
	{
		if (XCheckMaskEvent(data->display, -1, &event))
		{
			if (event.type == KeyPress)
			{
				XPutBackEvent(data->display, &event);
				return 1;
			}
			else if (event.type == ButtonPress)
			{
				XPutBackEvent(data->display, &event);
				return 1;
			}
			else
				return 0; }
		else
			return 0;
	}
}

char	wait_input(t_xdata *data)
{
	XEvent event;

	XFlush(data->display);
	while(42)
	{
		XNextEvent(data->display, &event);
		if (event.type == KeyPress)
			return XLookupKeysym(&event.xkey, 0);
		else if (event.type == ButtonPress)
			return event.xbutton.button;
	}
}
