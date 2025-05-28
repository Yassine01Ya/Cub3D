/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafilali <yafilali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:06:05 by wtoumi            #+#    #+#             */
/*   Updated: 2025/04/10 19:20:39 by yafilali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include "./get_next_line.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	char			*line;
	int				is_set;
	struct s_node	*next;
}					t_node;

typedef struct s_cub
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			**grid;
	int				floor[3];
	int				floor_color;
	int				ceiling[3];
	int				ceiling_color;
	int				colors_check[2];
	int				count_map_lines;
	int				count_map_cols;
	int				player_x;
	int				player_y;
	char			player_direction;
}					t_cub;

typedef enum e_color
{
	FLOOR = 0,
	CEILING = 1
}					t_color;

char				*ft_strdup(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);

int					read_file_cub(char *filename);
void				parse_color(t_node *node, t_cub *cube, t_color flag);

void				set_cub(t_cub *cub);
int					count_map_lines(void);
int					verify_extention(char *filename, char *cub_extention);

// LL
t_node				**ll_head(void);
t_node				*ll_new_node(char *data);
void				ll_add_node(t_node *node);
int					get_max_len(void);

void				ft_exit(char *msg, int status);
int					count_tab(char **tab);

void				set_config(char **line_path, t_node *node);
int					check_config_color(t_cub *cub);
int					check_empty_line(char *line);

t_cub				*get_cub(void);
void				check_map(t_cub *cub);
int					is_map_closed(t_cub *cub);
void				free_ll(void);
void				free_map(void);
void				init_cub(void);
void				free_double(char **str);
void				free_all(int stage);
void				free_textures(void);

#endif
