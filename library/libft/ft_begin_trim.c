/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:49:38 by dromanic          #+#    #+#             */
/*   Updated: 2017/11/26 20:27:04 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_begin_trim(const char *str)
{
	unsigned int i;

	i = 0;
	if (str)
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	return (i);
}