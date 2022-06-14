/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:54:40 by jeekim            #+#    #+#             */
/*   Updated: 2022/06/13 19:17:35 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <stdlib.h>

# define BUFFER_SIZE 333
# define KEY_ESC 53
# define KEY_W 13      
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_WINDOW_DESTROY 17

unsigned long long	g_row;
unsigned long long	g_col;
char				**g_map;
unsigned long long	g_x;
unsigned long long	g_y;
int					g_fd;
void				*g_mlx_ptr;
void				*g_win_ptr;
void				*g_img_ptr;
unsigned long long	g_movements;
unsigned long long	g_collectible_num;
unsigned long long	g_collected;
int					g_int_ary[5];

void	get_row_col(char **argv);
void	get_map(char **argv);
void	repetitive_statement(void);
void	char_to_img(void);
void	check_arg(int argc, char *sec_arg);
char	*ft_strcpy(char *dest, char *src);
int		go_up(void);
int		go_down(void);
int		go_left(void);
int		go_right(void);
int		key_press(int keycode);
void	total_collectibles(void);
void	currently_collected(void);
int		player_position(void);
void	only_01ecp(void);
void	missing_character(void);
void	check_map(void);
void	check_wall(void);
void	check_rectangular(void);

#endif