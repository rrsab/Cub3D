#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/errno.h>
# include <stdbool.h>
# include <fcntl.h>
//# include "../inc/colors.h"
//# include "../inc/macos_keyboard.h"
# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*addr;
	int			win_width;
	int			win_height;
	int			line_length;
	int			bpp;
	int			endian;
}	t_win;

typedef struct s_plr
{
	float		x;
	float		y;
	float		plane_x;
	float		plane_y;
	float		dir_x;
	float		dir_y;
	float		angle;
}	t_plr;

typedef struct s_txr
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		**matrix;
}				t_txr;

typedef struct s_txrs
{
	t_txr	*north;
	t_txr	*south;
	t_txr	*west;
	t_txr	*east;
}	t_txrs;

typedef struct s_map
{
	char		**map;
	char		**xpm;
	t_list		*map_list;
	int			floor;
	int			ceiling;
	int			width;
	int			height;
	bool		param_match;
	bool		map_match;
}	t_map;

typedef struct s_lodev
{
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			flag_hit;
	int			side;
	float		camera_x;
	float		ray_dir_x;
	float		ray_dir_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		perp_wall_dist;
	int			draw_start;
	int			draw_end;
	int			line_height;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
}	t_lodev;

typedef struct s_main
{
	t_win		*win;
	t_plr		*player;
	t_map		*map;
	t_lodev		*lodev;
	t_txrs		*txrs;
	int			zoom;
}	t_main;

#endif