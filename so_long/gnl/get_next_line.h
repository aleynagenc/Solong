/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:28:06 by agenc             #+#    #+#             */
/*   Updated: 2022/11/18 14:28:07 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
char	*ft_buff(int fd, char *str);
char	*get_next_line(int fd);
char	*ft_strjoin2(char *str, char *buff);
char	*ft_strchr2(char *str, int c);
char	*ft_get_line(char *str);
char	*ft_last_str(char *str);
#endif
