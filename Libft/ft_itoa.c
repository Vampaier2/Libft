/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalves <xalves@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:29:37 by xalves            #+#    #+#             */
/*   Updated: 2025/04/25 10:22:51 by xalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n)
	{
		n /= 10;
		++count;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str_itoa;
	int		len;

	len = count_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str_itoa = malloc(sizeof(char) * (len + 1));
	if (!str_itoa)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str_itoa[0] = '-';
	}
	if (n == 0)
		str_itoa[0] = '0';
	str_itoa[len] = '\0';
	while (n)
	{
		str_itoa[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str_itoa);
}
/*
//while (n) until n == 0
// in Swap() j = len - 1; does not include '\0'
int	main(void)
{
	//ft_itoa(423);
	char	*a = ft_itoa(-2147483648);
	printf("Final:%s\n", a);
	free(a);
	return (0);
} */
