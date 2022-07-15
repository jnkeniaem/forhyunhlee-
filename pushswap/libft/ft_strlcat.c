/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:37:12 by jeekim            #+#    #+#             */
/*   Updated: 2021/12/03 12:33:11 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	if (dstsize >= len + 1)
	{
		i = 0;
		while (src[i] && i < dstsize - 1 - len)
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = 0;
		return (ft_strlen(src) + len);
	}
	return (ft_strlen(src) + dstsize);
}
