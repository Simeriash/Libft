/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 07:20:56 by julauren          #+#    #+#             */
/*   Updated: 2026/01/24 07:29:48 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str, int *ctrl)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if ((num > INT_MAX && sign == 1) ||	(((num * sign) < INT_MIN)))
			break ;
		num = num * 10 + str[i] - 48;
		i++;
	}
	if ((num > INT_MAX && sign == 1) ||	(((num * sign) < INT_MIN)))
	{
		num = 0;
		*ctrl = 1;
	}
	return (sign * num);
}
