/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:12:46 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:12:50 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	new_p(t_list *lst)
{
	t_pointm *p;

	while (lst)
	{
		p = (t_pointm *)lst->content;
		p->x = p->source->x * (fdf_instance())->scale;
		p->y = p->source->y * (fdf_instance())->scale;
		p->z = p->source->z * (fdf_instance())->scale;
		lst = lst->next;
	}
	rotation(ENTER_KEY);
}

void		default_multi(t_pointm *p, t_list *lst)
{
	while (lst)
	{
		p = (t_pointm *)lst->content;
		p->x = p->source->x * (fdf_instance())->scale;
		p->y = p->source->y * (fdf_instance())->scale;
		p->z = p->source->z * (fdf_instance())->scale;
		lst = lst->next;
	}
}

void		multy(t_flag flag)
{
	t_list		*lst;
	t_pointm	*p;

	p = NULL;
	lst = (fdf_instance())->points;
	if ((fdf_instance())->scale > 289)
	{
		(fdf_instance())->scale -= 1;
	}
	else if ((fdf_instance())->scale <= 1)
	{
		(fdf_instance())->scale += 1;
	}
	else if (flag == PlUS)
	{
		(fdf_instance())->scale += 1;
		new_p(lst);
	}
	else if (flag == MINUS)
	{
		(fdf_instance())->scale -= 1;
		new_p(lst);
	}
	else
		default_multi(p, lst);
}

void		new_shift(t_key key)
{
	if (key == RIGHT_KEY)
		(fdf_instance())->shiftx += 10;
	else if (key == LEFT_KEY)
		(fdf_instance())->shiftx -= 10;
	else if (key == TOP_KEY)
		(fdf_instance())->shifty -= 10;
	else if (key == BOT_KEY)
		(fdf_instance())->shifty += 10;
	rotation(ENTER_KEY);
}

void		to_iso(t_list *lst)
{
	t_pointm	*fp;
	t_fdf		*fdf;
	double		p_x;
	double		p_y;

	fdf = fdf_instance();
	while (lst)
	{
		fp = (t_pointm *)lst->content;
		p_x = fp->x;
		p_y = fp->y;
		fp->x = fdf->shiftx + (p_x - p_y) * cos(0.523599);
		fp->y = fdf->shifty - fp->z + (p_x + p_y) * sin(0.523599);
		fp->fpoint->x = fp->x;
		fp->fpoint->y = fp->y;
		lst = lst->next;
	}
}
