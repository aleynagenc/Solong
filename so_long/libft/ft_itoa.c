/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:36:17 by agenc             #+#    #+#             */
/*   Updated: 2022/10/28 20:04:29 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	digit(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		j;
	long	nb;

	nb = n;
	j = digit(nb);
	str = (char *)malloc(j + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	str[j] = '\0';
	j--;
	while ((n < 0) <= j)
	{
		str[j] = (nb % 10) + 48;
		nb /= 10;
		j--;
	}
	return (str);
}
