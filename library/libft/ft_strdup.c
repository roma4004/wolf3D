/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 21:23:51 by dromanic          #+#    #+#             */
/*   Updated: 2018/11/03 14:25:39 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*new_str;

	len = ft_strlen(s1);
	if ((new_str = (char *)malloc(len + 1)))
	{
		i = -1;
		while (++i < len)
			new_str[i] = s1[i];
		new_str[i] = '\0';
	}
	return (new_str);
}
