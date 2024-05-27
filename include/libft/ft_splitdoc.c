/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:43:10 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:47:20 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpydoc(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (void *) dest;
	s = (void *) src;
	i = 0;
	if (!dest || !src)
		return (dest);
	if (n == 0 || (!s && !d) || s == d)
		return (d);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlcpydoc(char *dest, const char *src, size_t	size)
{
	size_t	src_len;
	size_t	temp;

	src_len = ft_strlen(src);
	if (!dest || size == 0)
		return (src_len);
	if (src_len < size)
		temp = src_len;
	else
		temp = size - 1;
	ft_memcpydoc(dest, src, temp);
	dest[temp] = '\0';
	return (src_len);
}

// void	*ft_callocdoc(size_t nitems, size_t size)
// {
// 	char	*ptr;
// 	size_t	i;

// 	i = 0;
// 	ptr = malloc(nitems * size);
// 	if (ptr == NULL)
// 		return (NULL);
// 	while (i < (nitems * size))
// 	{
// 		ptr[i] = '\0';
// 		i++;
// 	}
// 	return (ptr);
// }

// char	*ft_substrdoc(const char *s, unsigned int start, size_t len)
// {
// 	size_t	nouv_len;
// 	char	*dest;

// 	if (!s)
// 		return (NULL);
// 	if ((unsigned int)ft_strlen(s) < start)
// 		return (ft_strdup(""));
// 	nouv_len = ft_strlen(s);
// 	if (ft_strlen(s) < start + len)
// 		len = nouv_len - start;
// 	dest = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!dest)
// 		return (NULL);
// 	ft_strlcpydoc(dest, s + start, len + 1);
// 	return (dest);
// }

// static int	ft_nomb_str(const char *str, char c)
// {
// 	size_t	i;
// 	int		num;
// 	int		save;

// 	i = 0;
// 	num = 0;
// 	while (str[i])
// 	{
// 		while (str[i] == c && str[i])
// 			i++;
// 		if (str[i])
// 			num++;
// 		if (str[i] == '\'' || str[i] == '\"')
// 		{
// 			save = i;
// 			i++;
// 			while (str[save] != str[i])
// 				i++;
// 		}
// 		while (str[i] != c && str[i])
// 			i++;
// 	}
// 	return (num);
// }

// static void	*ft_freedoc(char **ptr)
// {
// 	int	i;

// 	i = 0;
// 	while (ptr[i])
// 	{
// 		free(ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// 	return (NULL);
// }

// char	**ft_splitdoc(char const *s, char c)
// {
// 	unsigned int	last_pos;
// 	unsigned int	i;
// 	int				k;
// 	char			**tab;

// 	tab = ft_callocdoc(sizeof(char *), (ft_nomb_str(s, c) + 1));
// 	if (!tab || !s)
// 		return (NULL);
// 	i = 0;
// 	k = 0;
// 	while (s[i] && k < (ft_nomb_str(s, c)))
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		if (s[i])
// 			last_pos = i;
// 		if (s[i] == '\'' || s[i] == '\"')
// 		{
// 			i++;
// 			while (s[i] != s[last_pos])
// 				i++;
// 		}
// 		while (s[i] && s[i] != c)
// 			i++;
// 		tab[k] = ft_substrdoc(s, last_pos, (i - last_pos));
// 		if (!tab[k])
// 			return (ft_freedoc(tab));
// 		k++;

// 	}
// 	return (tab);
// }
