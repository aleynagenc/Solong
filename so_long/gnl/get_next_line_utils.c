/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:28:17 by agenc             #+#    #+#             */
/*   Updated: 2022/11/18 14:28:29 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin2(char *str, char *buff)
{
	size_t	c;
	size_t	i;
	char	*pstr;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	pstr = malloc(sizeof(char) * ((ft_strlen2(str)) + ft_strlen2(buff) + 1));
	if (pstr == NULL)
		return (NULL);
	c = -1;
	i = 0;
	if (str)
		while (str[++c] != '\0')
			pstr[c] = str[c];
	while (buff[i] != '\0')
		pstr[c++] = buff[i++];
	pstr[ft_strlen2(str) + ft_strlen2(buff)] = '\0';
	free(str);
	return (pstr);
}

char	*ft_strchr2(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen2(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*my_line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	my_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!my_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		my_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		my_line[i++] = '\n';
	my_line[i] = '\0';
	return (my_line);
}

char	*ft_last_str(char *str)
{
	int		j;
	int		i;
	char	*my_line;

	j = 0;
	while (str[j] && str[j] != '\n')
		j++;
	if (!str[j])
	{
		free(str);
		return (NULL);
	}	
	my_line = (char *)malloc(sizeof(char) * (ft_strlen2(str) - j + 1));
	if (!my_line)
		return (NULL);
	j++;
	i = 0;
	while (str[j])
		my_line[i++] = str[j++];
	my_line[i] = '\0';
	free(str);
	return (my_line);
}
