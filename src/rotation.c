/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:13:08 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:13:12 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotation_x(t_key key)
{
	t_fdf		*fdf;
	t_list		*lst;
	t_pointm	*p;
	double		y;

	fdf = fdf_instance();
	lst = fdf->points;
	if (key == RSEVEN_KEY)
		fdf->rotate->x += 0.1;
	else if (key == REIGHT_KEY)
		fdf->rotate->x -= 0.1;
	while (lst)
	{
		p = (t_pointm *)lst->content;
		y = p->y;
		p->y = y * cos(fdf->rotate->x) + p->z * sin(fdf->rotate->x);
		p->z = -y * sin(fdf->rotate->x) + p->z * cos(fdf->rotate->x);
		lst = lst->next;
	}
}

static void	rotation_y(t_key key)
{
	t_fdf		*fdf;
	t_list		*lst;
	t_pointm	*p;
	double		x;

	fdf = fdf_instance();
	lst = fdf->points;
	if (key == RFOUR_KEY)
		fdf->rotate->y += 0.1;
	else if (key == RFIVE_KEY)
		fdf->rotate->y -= 0.1;
	while (lst)
	{
		p = (t_pointm *)lst->content;
		x = p->x;
		p->x = x * cos(fdf->rotate->y) + p->z * sin(fdf->rotate->y);
		p->z = -x * sin(fdf->rotate->y) + p->z * cos(fdf->rotate->y);
		lst = lst->next;
	}
}

static void	rotation_z(t_key key)
{
	t_fdf		*fdf;
	t_list		*lst;
	t_pointm	*p;
	double		x;

	fdf = fdf_instance();
	lst = fdf->points;
	if (key == RONE_KEY)
		fdf->rotate->z += 0.1;
	else if (key == RTWO_KEY)
		fdf->rotate->z -= 0.1;
	while (lst)
	{
		p = (t_pointm *)lst->content;
		x = p->x;
		p->x = x * cos(fdf->rotate->z) - p->y * sin(fdf->rotate->z);
		p->y = x * sin(fdf->rotate->z) + p->y * cos(fdf->rotate->z);
		lst = lst->next;
	}
	to_iso(fdf->points);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf->vecs);
}

void		rotation(t_key key)
{
	multy(NONE);
	rotation_x(key);
	rotation_y(key);
	rotation_z(key);
}
