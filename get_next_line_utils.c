/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:57:57 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/16 16:28:42 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *s)
{
	if (s != NULL)
	{
		free(s);
		s = NULL;
	}
}

size_t	ft_strlen(char *s)
{
	size_t	len;
	
	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_writeline(char *lines, char *line)
{
	char	*new_line;
	size_t	lines_len;
	size_t	ind;
	size_t	i;

	lines_len = ft_strlen(lines);
	if (ft_newline(lines))
		lines_len = ft_newline(lines);
	// printf("lines %zu\n", lines_len);
	// printf("line %zu\n", ft_strlen(line));
	new_line = malloc(lines_len + ft_strlen(line) + 1);
	if (!new_line)
	{
		ft_free(line);
		return (NULL);
	}
	ind = 0;
	if (line)
	{
		//write(1, "cahcha\n", 7);
		ind = -1;
		while (line[++ind])
			new_line[ind] = line[ind];
	}
	i = 0;
	while (lines[i] && lines[i] != '\n')
	{
		new_line[ind++] = lines[i];
		i++;
	}
	if (ft_newline(lines))
		new_line[ind++] = '\n';
	new_line[ind] = '\0';
	ft_free(line);
	return (new_line);
}

size_t	ft_newline(char *s)
{
	size_t	ind;

	if (!s)
		return (0);
	ind = -1;
	while (s[++ind])
	{
		if (s[ind] == '\n')
			return (++ind);
	}
	return (0);
}
