/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:04:42 by julauren          #+#    #+#             */
/*   Updated: 2026/01/25 10:56:28 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	len_1;
	size_t	len_2;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len_1 = ft_strlen(s1);
	else
		len_1 = 0;
	if (s2)
		len_2 = ft_strlen(s2);
	else
		len_2 = 0;
	dest = malloc(sizeof (*dest) * (len_1 + len_2 + 1));
	if (!dest)
		return (NULL);
	if (s1)
		ft_strlcpy(dest, s1, len_1 + 1);
	if (s2)
		ft_strlcpy(&dest[len_1], s2, len_2 + 1);
	return (dest);
}
