/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:46:14 by jeekim            #+#    #+#             */
/*   Updated: 2021/12/13 13:17:43 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	subs = (char *)malloc(len + 1);
	if (subs == NULL)
		return (NULL);
	while ((size_t)i < len && s[start] != 0)
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = 0;
	return (subs);
}
