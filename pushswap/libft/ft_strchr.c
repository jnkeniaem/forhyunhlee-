/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:33:14 by jeekim            #+#    #+#             */
/*   Updated: 2021/12/12 17:20:50 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((size_t)i < ft_strlen(s) + 1)
	{
		if (*(s + i) == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
