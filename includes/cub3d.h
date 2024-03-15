/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 13:10:00 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 15:01:53 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# define TILE_SIZE 64
# endif
/* ---------------------------------------------------------------------------*
							LIBRARIES
 --------------------------------------------------------------------------- */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
// # include <mlx.h>
/* ---------------------------------------------------------------------------*
							STRUCT
 --------------------------------------------------------------------------- */
typedef struct s_direction
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_direction;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_player
{
	float	x;
	float	y;
	float	rotation_angle;
}	t_player;

typedef struct s_map
{
	int	x;
	int	y;
}	t_map;

typedef struct s_cub_pars
{
	int			fd;
	char		*file_name;
	char		**map2d;
	char		*map;
	t_direction	directions;
	t_rgb		floor;
	t_rgb		celling;
	t_player	player;
	t_map		map_init;
}	t_cub_pars;
/* ---------------------------------------------------------------------------*
							FUNCTIONS UTILS
 --------------------------------------------------------------------------- */
char	*ft_getrest(char *rest, char *line);
int		ft_strlen_g(char *str);
char	*ft_strdup_g(char *rest);
char	*ft_strjoin_g(char *buffer, char *rest);
int		ft_strchr_g(char *buffer);
char	*read_file(int fd, char *rest);
char	*get_next_line(int fd);
char	*ft_getline(char *rest);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void const *dst, void const *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putendl_free(char *s, int fd, char *str);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
/* ---------------------------------------------------------------------------*
							FUNCTIONS PARSING
 --------------------------------------------------------------------------- */
void	ft_initialize(t_cub_pars *cub_pars);
void	clean_map(char **file_split);
void	parsing(t_cub_pars *cub, char **av);
void	check_file_extention(char *file_name);
int		is_cardinal_direction(char *line);
void	parse(t_cub_pars *cub);
int		ft_file_len(char **file_splite);
void	save_cardinal_direction(t_cub_pars *cub, char *line);
void	save_rgb(t_cub_pars *cub, char *line);
void	is_map(char *line);
void	is_graphics(t_cub_pars cub);
void	check_newline(char *map);
void	check_map(t_cub_pars *cub);
void	is_surrounded(t_cub_pars *cub);
void	one_player(t_cub_pars *cub);
void	player_surrounded(t_cub_pars *cub);
void	*ft_calloc_char(size_t count, size_t size, char c);
void	rect_map(t_cub_pars *cub);
void	get_p_position(t_cub_pars *cub);
void	check_newline(char *map);

#endif