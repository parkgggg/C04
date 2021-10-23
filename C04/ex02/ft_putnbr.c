/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupark <gupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:35:12 by gupark            #+#    #+#             */
/*   Updated: 2021/10/24 01:42:32 by gupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	sizecheck(int nb)
{
	int	input;
	int	size;

	input = nb;
	size = 1;
	while (input / 10 != 0)
	{
		size *= 10;
		input /= 10;
	}
	return (size);
}

void	ft_putnbr(int nb)
{
	int	input;
	int	size;

	if (nb != -2137483648)
	{
		size = sizecheck(nb);
		if (nb < 0)
		{
			input = nb * -1;
			ft_putchar('-');
		}
		else
			input = nb;
		while (size > 0)
		{
			ft_putchar((input / size) + '0');
			input %= size;
			size /= 10;
		}
	}
	else
		write(1, "-2147483648", 11);
}
