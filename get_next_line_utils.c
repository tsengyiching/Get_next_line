/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yictseng <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/24 14:57:42 by yictseng     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 19:03:58 by yictseng    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (ptr[i])
	{
		if (ptr[i] == c)
			return (char *)(s + i + 1);
		i++;
	}
	if (ptr[i] == c)
		return (char *)(s + i + 1);
	return (0);
}

char	*ft_split(char *save)
{
	int		i;
	int		j;
	char	*temp;
	char	*dst;

	i = 0;
	temp = save;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (0);
	j = 0;
	while (j < i)
	{
		dst[j] = temp[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		total_len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = (char *)malloc(sizeof(char) * (total_len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
