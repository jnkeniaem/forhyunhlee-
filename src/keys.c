/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:54:18 by jeekim            #+#    #+#             */
/*   Updated: 2022/06/13 19:17:50 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	go_up(void)
{
	if (g_map[g_y - 1][g_x] == 'E')
	{
		currently_collected();
		return (0);
	}
	else if (g_map[g_y - 1][g_x] == 'C')
		g_collected++;
	g_map[g_y - 1][g_x] = 'P';
	g_y--;
	g_map[g_y + 1][g_x] = '0';
	repetitive_statement();
	player_position();
	g_movements++;
	printf("movements : %llu, (x, y): (%llu, %llu)\n", g_movements, g_x, g_y);
	return (0);
}

int	go_down(void)
{
	if (g_map[g_y + 1][g_x] == 'E')
	{
		currently_collected();
		return (0);
	}
	else if (g_map[g_y + 1][g_x] == 'C')
		g_collected++;
	g_map[g_y + 1][g_x] = 'P';
	g_y++;
	g_map[g_y - 1][g_x] = '0';
	repetitive_statement();
	player_position();
	g_movements++;
	printf("movements : %llu, (x, y): (%llu, %llu)\n", g_movements, g_x, g_y);
	return (0);
}

int	go_left(void)
{
	if (g_map[g_y][g_x - 1] == 'E')
	{
		currently_collected();
		return (0);
	}
	else if (g_map[g_y][g_x - 1] == 'C')
		g_collected++;
	g_map[g_y][g_x - 1] = 'P';
	g_x--;
	g_map[g_y][g_x + 1] = '0';
	repetitive_statement();
	player_position();
	g_movements++;
	printf("movements : %llu, (x, y): (%llu, %llu)\n", g_movements, g_x, g_y);
	return (0);
}

int	go_right(void)
{
	if (g_map[g_y][g_x + 1] == 'E')
	{
		currently_collected();
		return (0);
	}
	else if (g_map[g_y][g_x + 1] == 'C')
		g_collected++;
	g_map[g_y][g_x + 1] = 'P';
	g_x++;
	g_map[g_y][g_x - 1] = '0';
	repetitive_statement();
	player_position();
	g_movements++;
	printf("movements : %llu, (x, y): (%llu, %llu)\n", g_movements, g_x, g_y);
	return (0);
}

int	key_press(int keycode)
{
	if ((keycode == KEY_W) && (g_map[g_y - 1][g_x] != '1'))
		go_up();
	else if ((keycode == KEY_S) && (g_map[g_y + 1][g_x] != '1'))
		go_down();
	else if ((keycode == KEY_A) && (g_map[g_y][g_x - 1] != '1'))
		go_left();
	else if ((keycode == KEY_D) && (g_map[g_y][g_x + 1] != '1'))
		go_right();
	else if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
