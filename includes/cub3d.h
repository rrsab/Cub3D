#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/errno.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define FOV 66
# define ROTATION_STEP 0.11F
# define STEP 0.20F

# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define SILVER		0xC0C0C0
# define GRAY		0x808080
# define OLIVE		0x808000
# define YELLOW		0xFFFF00
# define JAFFA		0xEF8633
# define SAFFRON	0xF3AF3D
# define RED		0xFF0000
# define MAROON		0x800000
# define BRICK		0xC2294E
# define GREEN		0x008000
# define TEAL		0x008080
# define AQUA		0x00FFFF
# define LIME		0x00FF00
# define BLUE		0x0000FF
# define NAVY		0x000080
# define PURPLE		0x800080
# define FUCHSIA	0xFF00FF
# define DISCO		0x9A1F6A
# define FLAMINGO	0xEC4B27
# define INDIGO		0x4b0082

# define STDIN 0
# define STDOUT 1
# define STDERR 1

# define MOUSE_LEFT_BUTTON		1
# define MOUSE_RIGHT_BUTTON		2
# define MOUSE_SCROLL_BUTTON	3
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5

# define ARROW_UP				126
# define ARROW_DOWN				125
# define ARROW_LEFT				123
# define ARROW_RIGHT			124

# define NUM_PAD_0				82
# define NUM_PAD_1				83
# define NUM_PAD_2				84
# define NUM_PAD_3				85
# define NUM_PAD_4				86
# define NUM_PAD_5				87
# define NUM_PAD_6				88
# define NUM_PAD_7				89
# define NUM_PAD_8				91
# define NUM_PAD_9				92
# define NUM_PAD_PLUS			69
# define NUM_PAD_MINUS			78

# define MAIN_PAD_W				13
# define MAIN_PAD_D				2
# define MAIN_PAD_S				1
# define MAIN_PAD_A				0
# define MAIN_PAD_B				11
# define MAIN_PAD_V				9
# define MAIN_PAD_0				29
# define MAIN_PAD_1				18
# define MAIN_PAD_2				19
# define MAIN_PAD_3				20
# define MAIN_PAD_4				21
# define MAIN_PAD_5				23
# define MAIN_PAD_6				22
# define MAIN_PAD_7				26
# define MAIN_PAD_8				28
# define MAIN_PAD_9				25
# define MAIN_PAD_ESC			53
# define MAIN_PAD_PLUS			24
# define MAIN_PAD_MINUS			27
# define MAIN_PAD_SPACE			49
# define MAIN_PAD_LESS			43
# define MAIN_PAD_MORE			47
# define MAIN_PAD_ENTER			36
# define MAIN_PAD_DELETE		117
# define MAIN_PAD_R_SHIFT		258

# define BUFFER_SIZE 1

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

typedef struct s_lst
{
	char			*val;
	struct s_lst	*next;
}			t_lst;

typedef struct s_map
{
	char		**map;
	char		**xpm;
	t_lst		*map_l;
	int			floor;
	int			ceiling;
	int			width;
	int			height;
	bool		param_done;
	bool		map_done;
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
	t_plr		*plr;
	t_map		*map;
	t_lodev		*lodev;
	t_txrs		*txrs;
	int			zoom;
}	t_m;

//utils
int			get_next_line(int fd, char **line);
void		*cb_malloc_x(size_t size);
void		ft_init_player(t_m *data);
float		ft_degree_to_ratio(float degree);
void		ft_init_struct(t_m *data);
void		ft_init_map(t_map *m);

//rendering
void		cb_rendering(t_m *data);
void		cb_render_cub(t_m *data);
void		cb_render_mini_map(t_m *data);
void		cb_render_floor_ceiling(t_m *data);
void		cb_mlx_pixel_put(t_win *win, int x, int y, int color);

//cb_calculate
void		ft_calc_ray_position_len_direction(t_m *data, int x_line);
void		ft_calc_step_and_side_dist(t_m *data);
void		check_which_wall_was_hitted(t_m *data);
void		ft_calc_lowest_and_highest_pixel(t_m *data);
void		ft_calc_value_of_wall_x(t_m *data);

//events & keys
int			cb_terminate(t_m *data);
int			cb_handle_events(t_m *data);
int			cb_handle_keyboard(int key, t_m *data);
void		cb_handle_ad_keys(int key, t_m *data);
void		cb_handle_ws_keys(int key, t_m *data);
void		cb_handle_arrows(int key, t_m *data);

//parsing
void		ft_lstdelone(t_lst *lst);
void		ft_lstclear(t_lst **lst);
void		ft_lstadd_back(t_lst **head, t_lst *new);
t_lst		*ft_lstnew(char *content);
void		ft_error(char *str);
int			cb_strchr(const char *str, int c);
int			parsing(int ac, char *file, t_m *all);
int			check_wall(char **map, int y, int x);
int			check_double_player(t_map *m);
void		check_map(t_map *m);
void		check_simbol(t_lst *map_l);
int			check_file(int ac, char *file);
void		get_tex_and_color(char *str, t_map *m);
void		find_player(t_plr *plr, t_map *m);
void		setup_texture(t_m *all, t_txr *txr, char *file);
void		open_texture(t_m *all);
void		make_map(t_map *data);
int			create_trgb(int t, int r, int g, int b);
int			cb_strchr(const char *str, int c);
uint32_t	color_pixel_texture(t_txr *img, int i, int j);
int			cb_isdigit_str(char *str);

#endif