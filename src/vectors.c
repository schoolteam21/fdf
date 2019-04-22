/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:13:51 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:13:57 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_color(t_point *start, t_point *end)
{
	t_fdf *fdf;

	fdf = fdf_instance();
	if ((start->z > fdf->minz && start->z < fdf->maxz) ||
			(end->z > fdf->minz && end->z < fdf->maxz)
		|| (start->z == fdf->maxz && end->z == fdf->minz && start->z != end->z)
	|| ((start->z == fdf->minz && end->z == fdf->maxz
			&& start->z != end->z)))
		return (GREEN);
	if (start->z == fdf->minz || end->z == fdf->minz)
		return (RED);
	return (BLUE);
}

t_vector	*add_get_vectors(t_point *start, t_point *end, t_flag flag)
{
	static t_vector	*vectors;
	t_vector		*new;

	if (flag == GIVE)
		return (vectors);
	if (!vectors)
	{
		vectors = malloc(sizeof(t_vector));
		vectors->start = start;
		vectors->end = end;
		vectors->color = check_color(start, end);
		vectors->next = NULL;
	}
	else
	{
		new = malloc(sizeof(t_vector));
		new->start = start;
		new->end = end;
		new->next = vectors;
		new->color = check_color(start, end);
		vectors = new;
	}
	return (vectors);
}

void		vec_init(void)
{
	t_list	*lst;
	t_point	*point;
	t_point	*fnd_point;

	lst = (fdf_instance())->points;
	while (lst)
	{
		point = ((t_pointm *)lst->content)->fpoint;
		if ((fnd_point = find_point((new_point(point, RIGHT)))))
			add_get_vectors(point, fnd_point, SAVE);
		if ((fnd_point = find_point((new_point(point, BOT)))))
			add_get_vectors(point, fnd_point, SAVE);
		lst = lst->next;
	}
	free(new_point(point, LEFT));
	(fdf_instance())->vecs = add_get_vectors(NULL, NULL, GIVE);
}
