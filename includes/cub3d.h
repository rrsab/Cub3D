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
# include "macos_keyboard.h"
# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define STEP 0.2f
# define ANGLE 0.11f

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

typedef struct s_player
{
	float		x;
	float		y;
	float		plane_x;
	float		plane_y;
	float		dir_x;
	float		dir_y;
	float		angle;
}	t_player;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		**matrix;
}				t_texture;

typedef struct s_textures
{
	t_texture	*north;
	t_texture 	*south;
	t_texture 	*west;
	t_texture 	*east;
}	t_textures;

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
	t_player	*player;
	t_map		*map;
	t_lodev		*lodev;
	t_textures	*textures;
	int			zoom;
}	t_main;

int		count_of_symbols(char *str, char symbol);
bool	str_isdigit(char *str);

int		check_file(int argc, char *file);
void	check_map_symbols(t_list *map_list);
void	check_map(t_map *map);

void	init_map(t_map *data);
void	map_creation(t_map *map);

void 	init_player(t_main *data);
void	find_player(t_player *player, t_map *map);

void	get_text_and_color(char *str, t_map *map);

void	parsing(int argc, char *file, t_main *data);

void	init_mlx(t_win *win);
void	init_lodev_struct(t_lodev *lodev);
void	init_main_struct(t_main *data);

void	get_textures(t_main *data);

void	rendering_floor_and_ceiling(t_main *data);
void	rendering_environment(t_main *data);
void	rendering(t_main *data);

void	handler_events(t_main *data);

#endif