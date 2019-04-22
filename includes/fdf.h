/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijate-bl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:10:32 by ijate-bl          #+#    #+#             */
/*   Updated: 2019/04/21 15:10:40 by ijate-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"

# define WIDTH 2500
# define HIGHT 1300
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0xFFFF00

typedef enum	e_key
{
	RIGHT_KEY = 124,
	LEFT_KEY = 123,
	ESC_KEY = 53,
	TOP_KEY = 126,
	BOT_KEY = 125,
	RSEVEN_KEY = 89,
	REIGHT_KEY = 91,
	RFOUR_KEY = 86,
	RFIVE_KEY = 87,
	RONE_KEY = 83,
	RTWO_KEY = 84,
	PLUS_KEY = 69,
	MINUS_KEY = 78,
	ENTER_KEY = 36
}				t_key;

typedef struct	s_hello_norm
{
	int deltax;
	int deltay;
	int error;
	int deltaerr;
	int p;
	int diry;
}				t_hello_norm;

typedef enum	e_flag
{
	LEFT,
	RIGHT,
	TOP,
	BOT,
	GIVE,
	SAVE,
	PlUS,
	MINUS,
	NONE
}				t_flag;

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

typedef struct	s_pointm
{
	t_point	*source;
	double	x;
	double	y;
	double	z;
	t_point	*fpoint;
}				t_pointm;

typedef struct	s_vector
{
	t_point			*start;
	t_point			*end;
	int				color;
	struct s_vector	*next;
}				t_vector;

typedef struct	s_rotate
{
	double x;
	double y;
	double z;
}				t_rotate;

typedef struct	s_fdf
{
	t_list		*points;
	t_vector	*vecs;
	t_rotate	*rotate;
	void		*mlx;
	void		*win;
	int			scale;
	int			shiftx;
	int			shifty;
	int			maxz;
	int			minz;
}				t_fdf;

t_vector		*new_vector(t_point *start, t_point *end);
void			put_vector(t_vector **vec, t_vector *new_vec);
t_fdf			*fdf_instance(void);
int				read_map(int fd, int x, int y);
t_pointm		*pointm_from_list(t_list *lst);
int				pointcmp(t_point *p1, t_point *p2);
t_point			*new_point(t_point *point, t_flag flag);
t_point			*find_point(t_point *point);
void			vec_init(void);
void			multy(t_flag flag);
void			to_iso(t_list *lst);
void			draw_map(t_vector *vec);
int				key_press(int keycode, void *param);
void			rotation(t_key key);
void			new_shift(t_key key);
void			empty_error(void);
void			bad_file_error(void);
void			bad_map(void);
int				valid_map(const int fd);
void			put_y(t_hello_norm norm, int color, t_point start, t_point end);
void			put_x(t_hello_norm norm, int color, t_point start, t_point end);

#endif
