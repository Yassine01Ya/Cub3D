/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:06:18 by wtoumi            #+#    #+#             */
/*   Updated: 2025/05/28 22:01:58 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include "cub3d.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BLOCK 50

# define WIDTH 2000
# define HEIGHT 2000

# ifndef MAC
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define LEFT 65361
#  define RIGHT 65363
#  define ESC 65307
# else
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define LEFT 123
#  define RIGHT 124
# endif

# define PI_M 3.141592653

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define PLAYER_RADIUS 75            
# define MINIMAP_SCALE 0.3            
# define MINIMAP_MARGIN 20
# define MINIMAP_PLAYER_SIZE 4
# define MINIMAP_BG_COLOR 0x000000
# define MINIMAP_WALL_COLOR 0xFFFFFF
# define MINIMAP_PLAYER_COLOR 0xFF0000
# define MINIMAP_BORDER_COLOR 0xFFFFFF

typedef struct s_center
{
	int					center_x;
	int					center_y;
}						t_center;

typedef struct s_pointdir
{
	int					x;
	int					y;
}						t_pointdir;

typedef struct s_pminimap
{
	float				dir_length;
	float				dir_x;
	float				dir_y;
	float				dx;
	float				dy;
	float				steps;
	float				x_inc;
	float				y_inc;
	float				x;
	float				y;
}						t_pminimap;

typedef struct s_draw_cell
{
	int					x;
	int					y;
	int					wall_size;
	float				offset_x;
	float				offset_y;
}						t_draw_cell;

typedef struct s_wall_block
{
	int					wall_x;
	int					wall_y;
	int					wall_size;
}						t_wall_block;

typedef struct s_ray_data
{
	float				ray_x;
	float				ray_y;
	float				prev_x;
	float				prev_y;
	int					wall_dir;
	int					start_y;
	int					end_y;
	float				x_pixel;
}						t_ray_data;

typedef struct s_player
{
	float				x;
	float				y;
	float				angle;

	bool				key_up;
	bool				key_down;
	bool				key_left;
	bool				key_right;

	bool				left_rotate;
	bool				right_rotate;
}						t_player;

typedef struct s_image
{
	void				*handler;
	char				*data;
	int					bpp;
	int					size_len;
	int					endian;
	int					width;
	int					height;
}						t_image;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	char				*data;
	void				*img;

	int					bpp;
	int					size_len;
	int					endian;
	t_player			player;
	char				**map;
	int					map_lines;
	int					map_cols;
	int					map_width;
	int					map_height;
	t_image				wall_tex[4];
}						t_game;

void					init_player(t_player *player, t_cub *cub);
int						key_release(int keycode, t_player *player);
int						key_press(int keycode, t_game *game);
void					move_player(t_player *player, t_game *game);

void					put_color_background(t_game *game, int h_start,
							int h_max, int color);
void					draw_line(t_player *player, t_game *game, float start_x,
							int i);

float					fixed_dist(t_player *player, float x2, float y2);
void					calculate_wall_height(t_player *player, float ray_x,
							float ray_y, t_ray_data *ray);
int						dwall_dir(float ray_x, float ray_y, float prev_x,
							float prev_y);
bool					touch(float px, float py, t_game *game);
int						draw_loop(t_game *game);
void					init_game(t_game *game, t_cub *cub);
void					draw_minimap(t_game *game);
void					put_pixel(int x, int y, int color, t_game *game);
int						esc_window(int keycode, t_game *game);
int						close_window(t_game *game);
int						esc_close(int keycode, void *param);
int						key_esc(int keycode, void *param);
unsigned int			get_img_pixel_at(t_image *img, int x, int y);

//

void					trace_ray(float start_x, t_player *player,
							t_ray_data *ray, t_game *game);
void					clear_image(t_game *game);

//bonus
bool					is_in_circle(int x, int y, t_center *c);
void					draw_filled_circle(t_center *c, int radius,
							int color, t_game *game);
void					draw_minimap_walls(t_center *c, float offset_x,
							float offset_y, t_game *game);
void					draw_minimap_player(t_center *c, t_game *game);
void					init_textures(t_game *game, t_cub *cub);
void					init_game_for_main(void);
void					create_map(t_cub *cub);
int						draw_loop_bonus(t_game *game);

#endif
