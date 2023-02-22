/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:32:51 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/13 21:32:13 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

int	*ft_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bp / 8));
	*(int *)dst = color;
	return ((int *) dst);
}

//Z. 22 unsigned int * notwendig? -> wird anscheinend von mlx erwartet.
//Z. 20 Der Pointer wird um y Zeilen (line_length) nach unten verschoben,
// 		und um x Pixel (bits_per_pixel / 8) nach rechts.