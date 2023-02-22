/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vziegler <vziegler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:03:12 by vziegler          #+#    #+#             */
/*   Updated: 2023/02/15 18:22:41 by vziegler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/fdf.h"
#include "./Header/libft.h"

void	ft_height(t_fdf *data, char *map)
{
	int		fd;
	char	*ln;
	char	**arr;

	data->height = 0;
	data->width = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_print_error("Open error.");
	ln = get_next_line(fd);
	arr = ft_split(ln, ' ');
	while (ln)
	{
		data->height++;
		free(ln);
		ln = get_next_line(fd);
	}
	while (arr[data->width] && arr[data->width][0] != '\n')
		data->width++;
	free(ln);
	ft_free_arr(arr);
	close(fd);
}

// Ermittelt die Anzahl der Zeilen der Map (42.fdf: 11)