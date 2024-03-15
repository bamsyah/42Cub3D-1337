/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:07:09 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 02:28:03 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src > dst)
		ft_memcpy(dst, src, len);
	else if (src < dst)
	{
		while (len--)
		{
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	return (dst);
}
