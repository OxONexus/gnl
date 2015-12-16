/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:00:25 by dda-silv          #+#    #+#             */
/*   Updated: 2015/12/16 14:59:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*ret;

	if (!dst || !src)
		return (dst);
	ret = dst;
	if (dst < src)
		while ((size_t)(dst - ret) < len)
			*(t_byte *)dst++ = *(t_byte *)src++;
	else
		while (len-- > 0)
			((t_byte *)dst)[len] = ((t_byte *)src)[len];
	return (ret);
}
