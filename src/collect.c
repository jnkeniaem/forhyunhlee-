/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:54:15 by jeekim            #+#    #+#             */
/*   Updated: 2022/06/13 19:34:46 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	total_collectibles(void)
{
	g_y = 0;
	while (g_y < g_row)
	{
		g_x = 0;
		while (g_x < g_col)
		{
			if (g_map[g_y][g_x] == 'C')
				g_collectible_num++;
			g_x++;
		}
		g_y++;
	}
}

void	currently_collected(void)
{
	if (g_collected == g_collectible_num)
	{
		printf("Collected all the collectible(s). Bye ~");
		exit(EXIT_SUCCESS);
	}
}
