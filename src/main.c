/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:54:06 by jeekim            #+#    #+#             */
/*   Updated: 2022/06/13 19:34:43 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_arg(int argc, char *sec_arg)
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		printf("Error\nneed more argument.");
		exit(EXIT_SUCCESS);
	}
	i = ft_strncmp(sec_arg + ft_strlen(sec_arg) - 4, ".ber", 4);
	if (i != 0)
	{
		printf("Error\n.ber file is needed.");
		exit(EXIT_SUCCESS);
	}
}

int	player_position(void)
{
	g_y = 0;
	while (g_y < g_row)
	{
		g_x = 0;
		while (g_x < g_col)
		{
			if (g_map[g_y][g_x] == 'P')
				return (0);
			g_x++;
		}
		g_y++;
	}
	return (0);
}

int	mouse_press(void)
{
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	check_arg(argc, argv[1]);
	get_row_col(argv);
	get_map(argv);
	check_map();
	total_collectibles();
	g_mlx_ptr = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_ptr,
			64 * g_col, 64 * g_row, "jeekim's SoLong");
	repetitive_statement();
	player_position();
	mlx_hook(g_win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, 0);
	mlx_hook(g_win_ptr, X_EVENT_WINDOW_DESTROY, 0, &mouse_press, 0);
	system("leaks solong");
	mlx_loop(g_mlx_ptr);
	return (0);
}
