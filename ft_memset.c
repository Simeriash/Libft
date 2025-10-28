/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:36:42 by julauren          #+#    #+#             */
/*   Updated: 2025/10/15 08:48:40 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*t;
	size_t	i;

	t = s;
	i = 0;
	while (i < n)
	{
		t[i] = c;
		i++;
	}
	return (s);
}
