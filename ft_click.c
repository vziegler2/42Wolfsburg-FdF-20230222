/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_click.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:03:51 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/13 21:23:37 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

int	ft_click(int key, t_fdf *data)
{
	t_fdf	*buffer;

	buffer = data;
	if (key == 1)
		exit(1);
	return (0);
}
