/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:50:00 by julauren          #+#    #+#             */
/*   Updated: 2025/10/28 14:10:00 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*t;

	if (!s || !f)
		return (NULL);
	t = (char *)s;
	str = ft_calloc(ft_strlen(t) + 1, sizeof (*str));
	if (!str)
		return (NULL);
	i = 0;
	while (t[i] != '\0')
	{
		str[i] = (f)(i, t[i]);
		i++;
	}
	return (str);
}
