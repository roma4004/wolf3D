/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:41:00 by dromanic          #+#    #+#             */
/*   Updated: 2018/09/12 12:41:42 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double num, int exp)
{
	double	result;

	result = 1.0;
	while (exp > 0)
	{
		if (exp % 2 == 1)
			result *= num;
		exp >>= 1;
		num *= num;
	}
	return (result);
}
