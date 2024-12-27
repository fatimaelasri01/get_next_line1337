/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-asri <fel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:32:33 by fel-asri          #+#    #+#             */
/*   Updated: 2024/12/27 19:50:56 by fel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	len_s1 = 0;
	len_s2 = 0;
	if (!res)
		return (NULL);
	while (s1[len_s1])
	{
		res[len_s1] = s1[len_s1];
		len_s1++;
	}
	while (s2[len_s2])
	{
		res[len_s1 + len_s2] = s2[len_s2];
		len_s2++;
	}
	res[len_s1 + len_s2] = '\0';
	return (res);
}

char *ft_strlcpy(char *dest, char *src, int size)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}