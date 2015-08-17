/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revint32.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddi <aeddi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 17:54:19 by aeddi             #+#    #+#             */
/*   Updated: 2014/05/19 19:27:44 by aeddi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t	ft_revint32(uint32_t nb)
{
	uint32_t	rev;

	rev = ((nb >> 24) & 0xff) |
	((nb << 8) & 0xff0000) |
	((nb >> 8) & 0xff00) |
	((nb << 24) & 0xff000000);
	return (rev);
}