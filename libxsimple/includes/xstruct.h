/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xstruct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 14:24:12 by aeddi             #+#    #+#             */
/*   Updated: 2015/08/19 14:28:04 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XSTRUCT_H
# define XSTRUCT_H

# include <X11/Xlib.h>

typedef struct		s_xdata
{
	Display			*display;
	Window			window;
	GC				gc;
	Colormap		colormap;
	int				colormode;
	XFontStruct		*font;
}					t_xdata;

typedef struct		s_vector_2
{
	int				x;
	int				y;
}					t_vector_2;

#endif
