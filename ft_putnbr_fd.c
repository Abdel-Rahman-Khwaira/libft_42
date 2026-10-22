/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:50:53 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/22 16:21:57 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char		res[12];
	int			len;

	len = len_n(n);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		while (len - 1)
		{
			res[--len] = -(n % 10) + 48;
			n /= 10;
		}
		ft_putstr_fd(res, fd);
		return ;
	}
	while (len)
	{
		res[--len] = n % 10 + 48;
		n /= 10;
	}
	ft_putstr_fd(res, fd);
	return ;
}
