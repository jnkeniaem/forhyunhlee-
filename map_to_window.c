/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:11:01 by jeekim            #+#    #+#             */
/*   Updated: 2022/06/14 20:16:16 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	get_row_col(char **argv)
{
	char	*str;

	g_row = 0;
	g_col = 0;
	g_fd = open(argv[1], O_RDONLY);
	if (g_fd == -1)
	{
		printf("Error\nCan't open the file.");
		exit(EXIT_SUCCESS);
	}
	str = "temp";
	while (str)
	{
		str = get_next_line(g_fd);
		if (str)
			g_col = ft_strlen(str);
		free(str);
		g_row++;
	}
	/*
	str = get_next_line(g_fd);
	while (str)
	{
		if (str)
			g_col = ft_strlen(str);
		g_row++;
		str = get_next_line(g_fd);
		free(str);
	}*/
	//free(str);
	g_row--;
}

void	get_map(char **argv)
{
	g_map = malloc((g_row + 1) * sizeof(char *));
	g_fd = open(argv[1], O_RDONLY);
	if (g_fd == -1)
	{
		printf("Error\nCan't open the file.");
		exit(EXIT_SUCCESS);
	}
	while (g_y < g_row)
	{
		g_map[g_y] = get_next_line(g_fd);
		g_y++;
	}
	g_map[g_y] = NULL;
	g_y = 0;
}

void	char_to_img(void)
{
	int	img_width;
	int	img_height;

	g_img_ptr = mlx_xpm_file_to_image(g_mlx_ptr,
			"../imgs/tile.xpm", &img_width, &img_height);
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img_ptr,
		g_x * 64, g_y * 64);
	if (g_map[g_y][g_x] == '1')
		g_img_ptr = mlx_xpm_file_to_image(g_mlx_ptr,
				"../imgs/rock.xpm", &img_width, &img_height);
	else if (g_map[g_y][g_x] == '0')
		g_img_ptr = mlx_xpm_file_to_image(g_mlx_ptr,
				"../imgs/tile.xpm", &img_width, &img_height);
	else if (g_map[g_y][g_x] == 'E')
		g_img_ptr = mlx_xpm_file_to_image(g_mlx_ptr,
				"../imgs/exit2.xpm", &img_width, &img_height);
	else if (g_map[g_y][g_x] == 'C')
		g_img_ptr = mlx_xpm_file_to_image(g_mlx_ptr,
				"../imgs/mushroom.xpm", &img_width, &img_height);
	else
		g_img_ptr = mlx_xpm_file_to_image(g_mlx_ptr,
				"../hero.xpm", &img_width, &img_height);
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img_ptr,
		g_x * 64, g_y * 64);
}

void	repetitive_statement(void)
{
	g_y = 0;
	while (g_y < g_row)
	{
		g_x = 0;
		while (g_x < g_col)
		{
			char_to_img();
			g_x++;
		}
		g_y++;
	}
}
