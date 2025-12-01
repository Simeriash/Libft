/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:06:49 by julauren          #+#    #+#             */
/*   Updated: 2025/12/01 16:24:34 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_pt(char *str, int fd)
{
	size_t	len;
	int		i;

	if (!str)
	{
		i = write(fd, "(null)", 6);
		return (i);
	}
	len = ft_strlen(str);
	i = write(fd, str, len);
	return (i);
}
