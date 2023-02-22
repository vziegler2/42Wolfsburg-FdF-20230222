/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:15:00 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/13 21:32:40 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

void	ft_settings2(t_fdf *data, double zoom, double depth)
{
	data->zoom = zoom;
	data->depth = depth;
}
