/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsimple.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plastic </var/spool/mail/plastic>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 01:22:49 by plastic           #+#    #+#             */
/*   Updated: 2015/08/17 01:57:48 by plastic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XSIMPLE_H
# define XSIMPLE_H

# include <X11/Xlib.h>

typedef struct		s_xdata
{
	Display			*display;
	Window			window;
	GC				gc;
	Colormap		colormap;
	int				colormode;
}					t_xdata;

typedef struct		s_vector_2
{
	int				x;
	int				y;
}					t_vector_2;

#endif /* !XSIMPLE_H */
