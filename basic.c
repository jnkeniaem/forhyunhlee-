/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:40:43 by jeekim            #+#    #+#             */
/*   Updated: 2022/02/17 17:05:31 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *cnt)
{
	write(1, &c, 1);
	(*cnt)++;
}

void	ft_putstr(char *s, int *cnt)
{
	while (*s)
	{
		ft_putchar(*s, cnt);
		s++;
	}
}
