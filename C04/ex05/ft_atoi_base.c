/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupark <gupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 04:46:41 by gupark            #+#    #+#             */
/*   Updated: 2021/10/24 04:48:35 by gupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\v' || c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

int	base_valid(char *base)
{
	int	size;
	int	index;

	size = 0;
	while (base[size])
	{
		if (is_space(base[size]) == 1)
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

int in_base(char c, char *base)
{
    int index;

    index = 0;
    while(base[index])
    {
        if(c == base[index])
            return (index);
        index++;
    }
    return (0);
}
int mknumber(char *str, char *base)
{
    int base_size;
    int result;

    base_size = base_valid(base);
    result = 0;
    while(in_base(*str, base) > 0)
    {
        result *= base_size;
        result += in_base(*str, base);
        str++;
    }
    return (result);
}
int ft_atoi_base(char *str, char *base)
{
    int base_size;
    int minus;
    int result;

    result = 0;
    minus = 0;
    base_size = base_valid(base);
    if  (base_size > 0)
    {
        while   (is_space(*str) == 1)
            str++;
        while   (*str == '+' || *str == '-')
        {
            if(*str == '-')
                minus++;
            str++;
        }
        result = mknumber(str, base);
        if  (minus % 2 == 1)
            result *= -1;
        return (result); 
    }
    else
        return (0);    
}
