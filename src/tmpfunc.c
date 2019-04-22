/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmpfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:13:21 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:13:25 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pointm	*pointm_from_list(t_list *lst)
{
	return ((t_pointm *)lst->content);
}

int			pointcmp(t_point *p1, t_point *p2)
{
	if (p1->x == p2->x && p1->y == p2->y)
		return (1);
	return (0);
}

t_point		*new_point(t_point *point, t_flag flag)
{
	static t_point *new;

	if (!new)
		new = malloc(sizeof(t_point));
	*new = *point;
	if (flag == LEFT)
		new->x = new->x - 1;
	else if (flag == RIGHT)
		new->x = new->x + 1;
	else if (flag == TOP)
		new->y = new->y - 1;
	else if (flag == BOT)
		new->y = new->y + 1;
	return (new);
}

t_point		*find_point(t_point *point)
{
	t_list	*lst;
	t_point	*lstpoint;

	lst = (fdf_instance())->points;
	while (lst)
	{
		lstpoint = ((t_pointm *)lst->content)->fpoint;
		if (pointcmp(point, lstpoint))
			return (lstpoint);
		lst = lst->next;
	}
	return (NULL);
}
