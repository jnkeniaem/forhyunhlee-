/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:54:10 by jeekim            #+#    #+#             */
/*   Updated: 2022/06/13 19:34:45 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_rectangular(void)
{
	unsigned long long	len1;
	unsigned long long	len2;

	g_y = 0;
	while (g_y + 1 < g_row)
	{
		len1 = (unsigned long long)ft_strlen(g_map[g_y]);
		if (g_y + 1 == g_row - 1)
			len2 = (unsigned long long)ft_strlen(g_map[g_y + 1]) + 1;
		else
			len2 = (unsigned long long)ft_strlen(g_map[g_y + 1]);
		if (len1 != len2)
		{
			printf("Error\nThe map isn't rectangular.");
			exit(EXIT_SUCCESS);
		}
		g_y++;
	}
}

void	only_01ecp(void)
{
	g_y = 0;
	while (g_y < g_row)
	{
		g_x = 0;
		while (g_x < g_col)
		{
			if (g_map[g_y][g_x] == '0')
				g_int_ary[0] = 1;
			else if (g_map[g_y][g_x] == '1')
				g_int_ary[1] = 1;
			else if (g_map[g_y][g_x] == 'E')
				g_int_ary[2] = 1;
			else if (g_map[g_y][g_x] == 'P')
				g_int_ary[3] = 1;
			else if (g_map[g_y][g_x] == 'C')
				g_int_ary[4] = 1;
			else
			{
				printf("Error\n'0', '1', 'C', 'E', 'P' only.");
				exit(EXIT_SUCCESS);
			}
			g_x++;
		}
		g_y++;
	}
}

void	missing_character(void)
{
	if (!((g_int_ary[0] == 1) && (g_int_ary[1] == 1) \
	&& (g_int_ary[2] == 1) && (g_int_ary[3] == 1) && (g_int_ary[4] == 1)))
	{
		printf("Error\nMissing character(s) in map.");
		exit(EXIT_SUCCESS);
	}
}

void	check_wall(void)
{
	g_y = 0;
	while (g_y < g_row)
	{
		g_x = 0;
		while (((g_y == 0) || (g_y == g_row - 1)) && (g_x <= g_col -1))
		{
			if (g_map[g_y][g_x] != '1')
			{
				printf("Error\nWall should be composed of '1'.");
				exit(EXIT_SUCCESS);
			}
			g_x++;
		}
		while ((g_y > 0) && (g_y < g_row - 1) && (g_x <= g_col -1))
		{
			if ((g_x == 0 || g_x == g_col - 1) && (g_map[g_y][g_x] != '1'))
			{
				printf("Error\nWall should be composed of '1'.");
				exit(EXIT_SUCCESS);
			}
			g_x++;
		}
		g_y++;
	}
}

void	check_map(void)
{
	check_rectangular();
	only_01ecp();
	missing_character();
	check_wall();
}
