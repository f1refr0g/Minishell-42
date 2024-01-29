/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:50:51 by abeaudet          #+#    #+#             */
/*   Updated: 2022/12/20 13:27:39 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// stepare avant le bn
char	*ft_preline(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc(i + 1, sizeof * res);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

// separe ce qui a ete lu , apres le bn
char	*ft_postline(const char *s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	while (s && s[j])
		j++;
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc((j - i) + 1, sizeof * res);
	if (!res)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	return (res);
}

//read mon file et le stock dans buffer
void	ft_read(int fd, char **str, char **temp)
{
	char	*buffy;
	int		i;

	buffy = malloc(sizeof * buffy * (BUFFER_SIZE + 1));
	if (!buffy)
		return ;
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffy, BUFFER_SIZE);
		if (i == -1)
		{
			ft_free(&buffy, str, temp);
			return ;
		}
		buffy[i] = '\0';
		*temp = ft_strdup(*str);
		ft_free(str, 0, 0);
		*str = ft_strjoin(*temp, buffy);
		ft_free(temp, 0, 0);
		if (ft_endline(*str))
			break ;
	}
	ft_free(&buffy, 0, 0);
}

//stock ce qui a ete lu entre les 2 bn
char	*ft_lookline(char **buffer, char **temp)
{
	char	*line;

	*temp = ft_strdup(*buffer);
	ft_free(buffer, 0, 0);
	*buffer = ft_postline(*temp);
	line = ft_preline(*temp);
	ft_free(temp, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	temp = NULL;
	ft_read(fd, &buffer, &temp);
	if (buffer != NULL && *buffer != '\0')
		line = ft_lookline(&buffer, &temp);
	if (!line || *line == '\0')
	{
		ft_free(&buffer, &line, &temp);
		return (NULL);
	}
	return (line);
}
