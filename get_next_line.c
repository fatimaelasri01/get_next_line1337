/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-asri <fel-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:26:28 by fel-asri          #+#    #+#             */
/*   Updated: 2024/12/27 19:52:51 by fel-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	isretourline(char *str, int *p)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	*p = i;
	if (str[i] == '\n')
		return (1);
	return (0);
}

static char *getline(char **str, int p)
{
	char *gline;
	int i;

	i = 0;
	if (!(*str))
		return (NULL);
	gline = (char *)malloc((p + 1) * sizeof(char));
	if (!gline)
		return (free(*str), *str = NULL, NULL);
	gline = ft_strlcpy(gline, *str, p);
	while ((*str)[i])
	{
		(*str)[i] = (*str)[i + p];
		i++;
	}
	(*str)[i] = '\0';
	return (gline);
}

static char *add(char **dest, char *src)
{
	char *res;
	int	i;
	
	i = 0;
	if (!(*dest))
		res = ft_strjoin("", src);
	else
		res = ft_strjoin(*dest, src);
	if (!res)
	{
		free(*dest);
		*dest = NULL;
		return (NULL);
	}
	return (free(*dest), *dest = NULL, res);
	// while (res[i])
	// {
	// 	(*dest)[i] = res[i];
	// 	i++;
	// }
	// (*dest)[i] = '\0';
}
static void	reste(char **t, char **res)
{
	int i;
	
	i = 0;
	free(*t);
	if (*res == NULL)
		{
			(*t) = NULL;
			return ;
		}
	*t = malloc((ft_strlen(*res) + 1) * sizeof(char));
	while ((*res)[i])
	{
		(*t)[i] = (*res)[i];
		i++;
	}
	(*t)[i] = '\0';
	free(*res);
	*res = NULL;
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*tmp;
	int			pos;
	int			i;

	tmp = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (free(rest), rest = NULL, NULL);
	while (1)
	{
		if (isretourline(rest, &pos))
			break ;
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1 || i == 0)
		{
			if (i == -1)
				return (free(rest), rest = NULL, free(tmp), NULL);
			return (reste(&tmp, &rest), tmp);
		}	
		rest = add(&rest, tmp);
		if (rest == NULL)
			return (free(tmp), NULL);
	}
	line = getline(&rest, ++pos);
	if (!line)
		return (NULL);
	return (line);
}
