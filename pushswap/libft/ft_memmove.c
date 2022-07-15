/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:14:08 by jeekim            #+#    #+#             */
/*   Updated: 2021/11/29 18:15:01 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	dp = dst;
	sp = src;
	if (dp == NULL && sp == NULL)
		return (0);
	if (dp > sp)
	{
		while (len-- > 0)
			*(dp + len) = *(sp + len);
	}
	else
	{
		while (len-- > 0)
			*dp++ = *sp++;
	}
	return (dst);
}
