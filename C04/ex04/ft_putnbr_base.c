/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupark <gupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 03:20:25 by gupark            #+#    #+#             */
/*   Updated: 2021/10/24 04:31:53 by gupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	base_valid(char *base)
{
	int	size;
	int	index;

	size = 0;
	while (base[size])
	{
		if (base[size] < 32 || base[size] == 127)
			return (0);
		if (base[size] == '+' || base[size] == '-')
			return (0);
		index = size + 1;
		while (base[index])
		{
			if (base[size] == base[index])
				return (0);
			index++;
		}
		size++;
	}
	if (size <= 1)
		return (0);
	return (size);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	size = base_valid(base);
	if (size > 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			ft_putnbr_base((nbr * -1) / size, base);
			write(1, &base[-(nbr % size)], 1);
		}
		else
		{
			if (nbr < size)
				write(1, &base[nbr % size], 1);
			else
			{
				ft_putnbr_base(nbr / size, base);
				write(1, &base[nbr % size], 1);
			}
		}
	}
}
