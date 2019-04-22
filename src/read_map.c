/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:12:58 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:13:01 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pointm	*create_point(int x, int y, int z)
{
	t_pointm *p;

	if (!(p = malloc(sizeof(t_pointm))))
		exit(EXIT_FAILURE);
	if (!(p->source = malloc(sizeof(t_point))))
		exit(EXIT_FAILURE);
	if (!(p->fpoint = malloc(sizeof(t_point))))
		exit(EXIT_FAILURE);
	p->source->x = x;
	p->source->y = y;
	p->source->z = z;
	p->fpoint->x = x;
	p->fpoint->y = y;
	p->fpoint->z = z;
	return (p);
}

t_list		*point_to_list(t_pointm *point)
{
	static t_list *lst;

	if (!point)
		return (lst);
	if (!lst)
		lst = ft_lstnew(point, sizeof(t_pointm));
	else
		ft_lstadd(&lst, ft_lstnew(point, sizeof(t_pointm)));
	free(point);
	return (lst);
}

void		free_arr(char **arr)
{
	char **q;

	q = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(q);
}

int			read_map(int fd, int x, int y)
{
	char	*line;
	char	**arr;

	y = -1;
	while (get_next_line(fd, &line) && ft_strlen(line))
	{
		x = -1;
		y++;
		arr = ft_strsplit(line, ' ');
		while (arr[++x])
		{
			point_to_list(create_point(x, y, ft_atoi(arr[x])));
			if (ft_atoi(arr[x]) > (fdf_instance())->maxz)
				(fdf_instance())->maxz = ft_atoi(arr[x]);
			else if (ft_atoi(arr[x]) < (fdf_instance())->minz)
				(fdf_instance())->minz = ft_atoi(arr[x]);
		}
		ft_strdel(&line);
		free_arr(arr);
	}
	line ? ft_strdel(&line) : NULL;
	if (y == -1)
		return (0);
	(fdf_instance())->points = point_to_list(NULL);
	return (1);
}
