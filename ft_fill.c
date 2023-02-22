/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:19:16 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/14 18:51:13 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

void	ft_fill(t_fdf *data, char *map)
{
	char	**arr;
	char	*ln;
	int		fd;

	arr = NULL;
	ln = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_print_error("Open error.");
	data->mtrx = malloc(sizeof(int *) * data->height);
	if (!data->mtrx)
		ft_print_error("Malloc error.");
	ft_fill2(data, arr, ln, fd);
	close(fd);
}
